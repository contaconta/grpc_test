import sys
import numpy as np
import cv2
import time

NTIMES=1000

if __name__ == '__main__':
	if len(sys.argv)!=2:
		print "usage filename"
		sys.exit(1)
	processingTime=0
	for i in range(0,NTIMES):
		sttime=time.time()
		img = cv2.imread(sys.argv[1])
		cv2.imwrite("pout.jpg",img)
		edtime=time.time()
		processingTime+=(edtime-sttime)
	print "Time "+str(processingTime)+"ms"
