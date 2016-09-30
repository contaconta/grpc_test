import sys
import numpy as np
import cv2
import time
import gc

import grpc
import cvgrpc_pb2

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
		mess=cvgrpc_pb2.ImgCVMat(depth=idepth,width=iwidth,height=iheight)
		matArray=img.flatten()
		matArray = matArray.astype(np.int)
		mess.iarray.extend(matArray)
		return mess

	def deconvert(self,res):
		idepth=res.depth
		iwidth=res.width
		iheight=res.height
		print idepth
		if idepth==3:
			MatArray=np.array(res.iarray)
			img=MatArray.reshape(iheight,iwidth,idepth)
		else:
			MatArray=np.array(res.iarray)
			img=MatArray.reshape(iheight,iwidth)
		return img

def run(img,addr):
	con=CvGrpcConverter()
	channel = grpc.insecure_channel(addr+':50051')
	print "connect"
	stub=cvgrpc_pb2.CvGrpcServiceStub(channel)
	for i in range(0,NTIMES):
		reqMess=con.convert(img)
		#print "send req"
		res=stub.convertGaussian(reqMess)
		#print "recv res"
		processedImg=con.deconvert(res)
	return processedImg

if __name__ == '__main__':
	if len(sys.argv)!=4:
		print "usage serveraddr inputfilename outputfilename"
		sys.exit(1)
	img = cv2.imread(sys.argv[2])
	img = run(img,sys.argv[1])
	cv2.imwrite(sys.argv[3],img)
	print "end processing"