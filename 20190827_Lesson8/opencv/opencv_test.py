import os
import sys
import cv2
import time
import numpy as np


if os.path.exists('/dev/video0') == False:
    print "No Camera Devices."
    sys.exit(2)

Camera_ID = 0
cap = cv2.VideoCapture(Camera_ID) # Camera_ID
i = 0
while True:
    ret,frame = cap.read()
    cv2.imshow("Video",frame)
    #cv2.imwrite('Sample'+str(i)+'.jpg',frame)
    #i += 1
    #print i
    #time.sleep(1)
cap.release()
