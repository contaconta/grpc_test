import sys
import numpy as np
import cv2
import time
import gc

import grpc
import cvgrpc_bin_pb2

NTIMES=100

class CvGrpcConverter:
	
	def __init__(self):
		#self.tostTime=0
		pass

	def convert(self,img):
		idepth = img.ndim
		if idepth == 3:
			iwidth, iheight, idepth = img.shape
		else:
			iwidth, iheight = img.shape
		mess = cvgrpc_bin_pb2.ImgCVMat(depth = idepth, width = iwidth, height = iheight)
		MatArray = cv2.imencode(".jpg", img)
		mess.iarray = MatArray[1].tostring()
		return mess

	def deconvert(self,res):
		idepth = res.depth
		iwidth = res.width
		iheight = res.height
		MatArray = np.frombuffer(res.iarray, dtype = 'uint8')
		img = cv2.imdecode(MatArray, -1)
		return img

	#def printTypetime(self):
		#print "tosttime : "+str(self.tostTime)	

def run(img,addr):
	con = CvGrpcConverter()
	channel = grpc.insecure_channel(addr+':50051')
	print "connect"
	stub = cvgrpc_bin_pb2.CvGrpcServiceStub(channel)
	convtime,stubtime,deconvtime=(0,0,0)
	for i in range(0,NTIMES):
		sttime = time.time()
		reqMess = con.convert(img)
		edtime = time.time()
		convtime += (edtime - sttime)
		#print "send req"
		sttime = time.time()
		res = stub.convertGaussian(reqMess)
		edtime = time.time()
		stubtime += (edtime - sttime)
		#print "recv res"
		sttime = time.time()
		processedImg = con.deconvert(res)
		edtime = time.time()
		deconvtime += (edtime - sttime)
	print "convtime : " + str(convtime) + ", stubtime :" + str(stubtime) + ", deconvtime :" + str(deconvtime)
	return processedImg

if __name__ == '__main__':
	if len(sys.argv)!=4:
		print "usage serveraddr inputfilename outputfilename"
		sys.exit(1)
	img = cv2.imread(sys.argv[2])
	img = run(img,sys.argv[1])
	cv2.imwrite(sys.argv[3],img)
	print "end processing"