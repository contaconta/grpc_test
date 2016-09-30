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
		pass

	def convert(self,img):
		idepth=img.ndim
		if idepth==3:
			iwidth,iheight,idepth=img.shape
		else:
			iwidth,iheight=img.shape
		mess=cvgrpc_bin_pb2.ImgCVMat(depth=idepth,width=iwidth,height=iheight)
		mess.iarray = img.tostring()
		return mess

	def deconvert(self,res):
		idepth=res.depth
		iwidth=res.width
		iheight=res.height
		MatArray=np.frombuffer(res.iarray, dtype='uint8')
		if idepth==3:
			img=MatArray.reshape(iheight,iwidth,idepth)
		else:
			img=MatArray.reshape(iheight,iwidth)
		return img

def run(img,addr):
	con=CvGrpcConverter()
	channel = grpc.insecure_channel(addr+':50051')
	print "connect"
	stub=cvgrpc_bin_pb2.CvGrpcServiceStub(channel)
	for i in range(0,NTIMES):
		reqMess=con.convert(img)
		#print "send req"
		res=stub.convertGaussian(reqMess)
		#print "recv res"
		img=con.deconvert(res)
	processedImg=img
	return processedImg

if __name__ == '__main__':
	if len(sys.argv)!=4:
		print "usage serveraddr inputfilename outputfilename"
		sys.exit(1)
	img = cv2.imread(sys.argv[2])
	img = run(img,sys.argv[1])
	cv2.imwrite(sys.argv[3],img)
	print "end processing"