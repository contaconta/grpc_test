# Template Matching

import sys
import numpy as np
import cv2
import time

NTIMES=1000

if __name__ == '__main__':
	if len(sys.argv)!=3:
		print "usage imgfilename tempfilename"
		sys.exit(1)
	img = cv2.imread(sys.argv[1],0)
	tmp = cv2.imread(sys.argv[2],0)

	width,height = tmp.shape[::-1] 
	processingTime=0
	for i in range(0, NTIMES):
		sttime=time.time()
		res = cv2.matchTemplate(img,tmp,cv2.TM_CCOEFF_NORMED)
		edtime=time.time()
		processingTime+=(edtime-sttime)
		min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)
		top_left = max_loc
		bottom_right = [top_left[0]+width, top_left[1]+height]
	print "matched at ( "+str(top_left[0])+" , "+str(top_left[1])+" ) to ( "+str(bottom_right[0])+" , "+str(bottom_right[1])+" )."
	print "Time "+str(processingTime)+"ms"

