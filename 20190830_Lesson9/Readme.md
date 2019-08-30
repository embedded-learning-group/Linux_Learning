## The Basic Service Of Linux
我们在Linux默认安装了很多的基本服务，我们需要使用到的基本的服务例如：
1. **SSH Service**
上述第一个SSH 
Service代表着一般的网络登陆服务，我们可以通过这个服务登陆到远程的或者局域网的主机之上，登陆的方式为(用户名+密码):
```
username:pi
password:xxxxxx
```
当然我们还有其他的登陆方式，可以参考Reference文档。
2. **Crontab Service**
在第二个服务的功能是完成定时服务程序，通过修改crontab表中的内容，在不同的时间点，运行对应的程序，如下是具体的使用事例：`sudo 
crontab -e`
```
# Example of job definition:
# .---------------- minute (0 - 59)
# | .------------- hour (0 - 23)
# | | .---------- day of month (1 - 31)
# | | | .------- month (1 - 12) OR jan,feb,mar,apr ...
# | | | | .---- day of week (0 - 6) (Sunday=0 or 7) OR 
sun,mon,tue,wed,thu,fri,sat
# | | | | |
# * * * * * user-name command to be executed
2 * * * * * source period_shell.sh # Run the shell script per-minutes.
@reboot python reboot_running.py # Run the py script while the sys boot.
```
3. **FTP Service**  
文件传输协议（File Transfer 
Protocol，FTP）是用于在网络上进行文件传输的一套标准协议，它工作在 OSI 
模型的第七层，TCP 模型的第四层，即应用层，使用 TCP 传输而不是 
UDP，客户在和服务器建立连接前要经过一个“三次握手”的过程，保证客户与服务器之间的连接是可靠的，而且是面向连接，为数据传输提供可靠保证。  

## First Camera Try  
1. **Install python-opencv:**  `sudo apt-get install python-opencv`
2. **Raspistill Camera:**  `raspistill -o image.jpg`
3. **Capture the video:**  `raspivid -o mykeychain.h264 -t 10000 -w 1280 
-h 720`  
4. **Using the picamera Lib**  
```
# import the necessary packages
from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
camera.resolution = (640, 480)
camera.framerate = 32
camera.hflip = True
camera.vflip = True
rawCapture = PiRGBArray(camera, size=(640, 480))
# allow the camera to warmup
time.sleep(0.1)
# capture frames from the camera
for frame in camera.capture_continuous(rawCapture, format="bgr", 
use_video_port=True):
    # grab the raw NumPy array representing the image, then initialize 
the timestamp
    # and occupied/unoccupied text
    image = frame.array
    # show the frame
    cv2.imshow("Frame", image)
    key = cv2.waitKey(1) & 0xFF
    # clear the stream in preparation for the next frame
    rawCapture.truncate(0)
    # if the `q` key was pressed, break from the loop
    if key == ord("q"):
        break
```
Here we try to use the Opencv-Lib to deal with the Image data.  
5. **Install the opencv by opencv-source code.**
Step1. `wget https://github.com/opencv/opencv/archive/3.3.0.tar.gz`
Step2. `sudo apt-get install pkg-config libgtk2.0-dev pkg-config 
libavcodec-dev libavformat-dev libswscale-dev libjpeg-dev libpng-dev 
libtiff-dev libjasper-dev libdc1394-22-dev`
Step3. `tar -xzvf opencv-3.3.0.tar.gz`
Step4. `mkdir my_build_dir`
Step5. `cd my_build_dir`
Step6. `cmake ../opencv-3.3.0 -DWITH_GTK_2_X=ON 
-DCMAKE_INSTALL_PREFIX=/usr/local`
Step7. `make    # make -j4表示开4个线程来进行编译`
Step8. `make install`

## Reference
[SSH登陆](https://blog.csdn.net/li528405176/article/details/82810342)
[Crontab详解](https://www.cnblogs.com/longjshz/p/5779215.html)
[raspistill CMD](https://www.cnblogs.com/uestc-mm/p/7587783.html)
[Picamera-Lib](https://www.cnblogs.com/uestc-mm/p/7606855.html)
[安装OPENCV](https://www.cnblogs.com/uestc-mm/p/7338244.html)

## Homework
使用C语言完成简单的opencv图像的读取以及灰度图像转换相关程序，提交至Github.
