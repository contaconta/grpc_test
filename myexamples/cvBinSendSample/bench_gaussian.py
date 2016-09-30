# Apply Gaussian Fillter

import sys
#import numpy as np
import cv2
import time

NTIMES=100

if __name__ == '__main__':
	if len(sys.argv)!=2:
		print "usage filename"
		sys.exit(1)
	img = cv2.imread(sys.argv[1])
	processingTime=0
	for i in range(0,NTIMES):
		#sttime=time.time()
		retImg =cv2.GaussianBlur(img,(5,5),0)
		#edtime=time.time()
		#processingTime+=(edtime-sttime)
	cv2.imwrite("filterd.jpg",retImg)
	print "filter end"
	print "Time "+str(processingTime)+"ms"
