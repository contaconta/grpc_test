# 環境構築(GRPC,OpenCV)
## 構築環境
* OS : Ubuntu14.04LTS
* GRPCバージョン : 1.0.0
* Prtocol Buffersバージョン : 3.1.2
* OpenCVバージョン : 3.1.0

## GRPC
### C++の環境構築

```shell
$ [sudo] apt-get install build-essential autoconf libtool
$ git clone -b $(curl -L http://grpc.io/release) https://github.com/grpc/grpc
$ cd grpc
$ git submodule update --init
$ make
$ [sudo] make install
$ cd ./third_party/protobuf
$ make
$ sudo make install
```

### Pythonの環境構築
anacondaを用いて環境構築を行う。事前準備としてcondaの仮想環境を作成する
```shell
$ conda create -n ENV_NAME python=2.7 anaconda
$ source activate ENV_NAME
$ python -m pip install --upgrade pip
```
仮想環境上に入ったら、GRPCの環境構築を行う。
```shell
$ python -m pip install grpcio
$ python -m pip install grpcio-tools
```

### 構築の確認
C++,Pythonともにhelloworldのサンプルを実行する
#### C++

```shell
$ cd grpc/examples/cpp/helloworld/
$ make
$ #server側
$ ./greeter_server
$ #client側
$ ./greeter_client
```
#### Python

```shell
$ cd grpc/examples/python/helloworld/
$ #server側
$ python greeter_server.py
$ #client側
$ python greeter_client.py
```

## OpenCV
### C++の環境構築

今回はインストールディレクトリを$HOME/usr/local下とした。そのためほかのディレクトリにインストールする場合は適宜変更する。
```shell
$ mkdir -p usr/local/lib/
$ ls
$ mkdir opencv
$ cd opencv/
$ wget http://downloads.sourceforge.net/project/opencvlibrary/opencv-unix/3.1.0/opencv-3.1.0.zip
$ unzip opencv-3.1.0.zip
$ sudo apt-get update
$ sudo apt-get install build-essential libgtk2.0-dev libjpeg-dev libtiff4-dev libjasper-dev libopenexr-dev cmake python-dev python-numpy python-tk libtbb-dev libeigen3-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev libqt4-dev libqt4-opengl-dev sphinx-common texlive-latex-extra libv4l-dev libdc1394-22-dev libavcodec-dev libavformat-dev libswscale-dev default-jdk ant libvtk5-qt4-dev checkinstall
$ ls
$ cd opencv-3.1.0/
$ mkdir build
$ cd build/
$ #インストール先にディレクトリを変更する場合はCMAKE_INSTALL_PREFIXの値を変更する
$ cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=$HOME/usr/local -D WITH_TBB=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D WITH_FFMPEG=OFF -D BUILD_opencv_python2=ON ..
$ #/usr/locaｌ下以外にインストールするときは以下のパスを通す
$ # PKG_CONFIG_PATH=$HOME/local/opencvlibrary/lib/pkgconfig:$PKG_CONFIG_PATH
$ # export PKG_CONFIG_PATH
$ # LD_LIBRARY_PATH=$HOME/local/opencvlibrary/lib:$LD_LIBRARY_PATH
$ # export LD_LIBRARY_PATH
$ #
$ ~/.profile
$ vi ~/.profile
$ make -j4
$ sudo make install
$ source ~/.profile
$  sudo checkinstall
$ #ディレクトリは適宜変更する
$  sudo sh -c 'echo "$HOME/usr/local/lib" > /etc/ld.so.conf.d/opencv.conf'
$  sudo ldconfig
$  sudo cp 3rdparty/ippicv/unpack/ippicv_lnx/lib/intel64/libippicv.a $HOME/usr/local/lib
$  sudo cp ../3rdparty/ippicv/unpack/ippicv_lnx/lib/intel64/libippicv.a $HOME/usr/local/lib
```
### Pythonの環境構築
GRPCと同様にanaconda上で構築する
```shell
$ source activate ENV_NAME
$ conda install -c anaconda numpy=1.11.1
$ conda install -c menpo opencv3=3.1.0
```
### 構築の確認
#### C++
以下のソースをコンパイル、実行する
```cpp
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
  cout << "OpenCV version : " << CV_VERSION << endl;
  cout << "Major version : " << CV_MAJOR_VERSION << endl;
  cout << "Minor version : " << CV_MINOR_VERSION << endl;
  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
}
```
```shell
$  g++ -ggdb `pkg-config --cflags opencv` -o `basename testcv.cpp .cpp` testcv.cpp `pkg-config --libs opencv`
$ ./testcv
```

#### Python
```python
import numpy as np
import cv2
cv2.__version__
```
