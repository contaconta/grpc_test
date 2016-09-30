# OpenCVの簡易性能評価(C++ vs Python)
## はじめに
gRPCを使う目的として、「時間のかかる処理のみを高速な言語・サーバで実行する」ということがあげられる。
今回はネットワークレイテンシやProtocol Buffersのシリアライズ処理などを含めた性能評価をするわけだが、その前提として、もしC++とPythonで全く同じ処理を行った場合にどれだけの性能差があるかを事前に知っておき、そのうえで性能評価を行うアルゴリズムを検討する必要があると考えた。
## gRPCの性能評価について
今回は、OpenCVの画像処理を例に、「Pythonクライアントから画像をgRPCサーバに送信、C++で処理したうえで処理後の画像をクライアントに返す」という性能評価を行う
![性能評価イメージ](https://slack-files.com/T1WUW75A9-F2CDNQFHC-3008eaabae)
## 簡易性能評価に用いた処理
今回の簡易性能評価では
1. Gaussianフィルタ実行×1000回
2. テンプレートマッチング×1000回
3. 画像の読み書き(I/O)×1000回
の処理を行った。
また、簡易性能評価で使用したマシンは評価用サーバ(192.168.0.18)である。
## 結果
今回は1.～3.の処理をC++,Pythonでそれぞれ10回実行した
### 1. Gaussianフィルタ実行


    launch gaussian fillter in python
    real 1.69
    real 1.42
    real 1.34
    real 1.67
    real 1.56
    real 1.21
    real 1.33
    real 1.56
    real 1.53
    real 1.67

    launch gaussian fillter in C++
    real 1.74
    real 1.62
    real 1.73
    real 1.73
    real 1.70
    real 1.69
    real 1.56
    real 1.71
    real 1.73
    real 1.68
C++とpythonではほとんど速度差がなかった。むしろPythonの方が幾分か早い
### 2. テンプレートマッチング実行
    launch matching in python
    real 10.13
    real 11.66
    real 12.42
    real 12.31
    real 12.10
    real 11.60
    real 10.92
    real 11.29
    real 12.40
    real 12.18
    launch matching in C++
    real 36.40
    real 39.75
    real 39.25
    real 37.68
    real 37.86
    real 36.76
    real 39.19
    real 42.13
    real 38.82
    real 39.69
圧倒的にPythonの方が早い。普通は考えられない。
### 3. I/O処理
    launch io in python
    real 21.18
    real 21.96
    real 21.56
    real 20.25
    real 22.97
    real 21.05
    real 20.67
    real 19.89
    real 21.94
    real 20.52
    launch io in C++
    real 9.26
    real 8.91
    real 9.67
    real 9.64
    real 9.76
    real 9.72
    real 9.71
    real 8.79
    real 9.50
    real 7.50
こちらはC++の方が早かった。
## 考察
pythonのOpenCVは内部の演算をnumpyで処理している。numpyはCで実装＋高度な最適化が行われている。
そのためOpenCVの演算処理に関しては事実上「高度に最適化されたC」 vs 「C++」の速度勝負となってしまいPython側に軍配が上がる。
一方、I/O処理に関してはnumpyが肩代わりをすることがないため、C++の方が高速という結果となると考えられる。
## まとめ
今回行おうとしているgRPCの性能評価では、OpenCVの処理部分をC++サーバで処理するという構成である。しかし画像処理速度に関してはPythonの方が高速であるため、gRPCクライアントとgRPCサーバを同一マシン上に配置して性能評価を行った場合、ローカル上のPythonでの処理が最速であることがほぼ予測できてしまう。
そのため、クライアントとサーバの間に何らかの性能差を設けるか、評価に使う処理をOpenCV意外にする必要があると考えられる。
## 参考：テストに用いたソースコード
### 1. Gaussianフィルタ実行

```python
# Apply Gaussian Fillter

import sys
#import numpy as np
import cv2

NTIMES=1000

if __name__ == '__main__':
	if len(sys.argv)!=2:
		print "usage filename"
		sys.exit(1)
	img = cv2.imread(sys.argv[1])
	print type(img)
	for i in range(0,NTIMES):
		img =cv2.GaussianBlur(img,(5,5),0)
	cv2.imwrite("filterd.jpg",img)
	print "filter end"

```

```cpp
//Apply Gaussian Fillter

#include <iostream>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


#define NTIMES 1000
#define KERNEL_LENGTH 5

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
	Mat img;

	if(argc!=2){
		cerr<<"usage filename"<<endl;
		exit(1);
	}
	img=imread(argv[1]);
	for(int i=0;i<NTIMES;i++)
		GaussianBlur( img, img, Size( KERNEL_LENGTH, KERNEL_LENGTH ),0);
	imwrite("cfilterd.jpg",img);
	cerr<<"filter end"<<endl;
	return 0;
}
```
### 2. テンプレートマッチング実行

```python
# Template Matching
import sys
import numpy as np
import cv2

NTIMES=1000

if __name__ == '__main__':
	if len(sys.argv)!=3:
		print "usage imgfilename tempfilename"
		sys.exit(1)
	img = cv2.imread(sys.argv[1],0)
	tmp = cv2.imread(sys.argv[2],0)

	width,height = tmp.shape[::-1]

	for i in range(0, NTIMES):
		res = cv2.matchTemplate(img,tmp,cv2.TM_CCOEFF_NORMED)
		min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)
		top_left = max_loc
		bottom_right = [top_left[0]+width, top_left[1]+height]
	print "matched at ( "+str(top_left[0])+" , "+str(top_left[1])+" ) to ( "+str(bottom_right[0])+" , "+str(bottom_right[1])+" )."
```

```cpp
//Template Matching

#include <iostream>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#define NTIMES 1000

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
	Mat img,tmp,result;
	Point top_left;
	if(argc!=3){
		cerr<<"usage imgfilename tmpfilename"<<endl;
		exit(1);
	}

	img=imread(argv[1]);
	tmp=imread(argv[2]);
	int width=tmp.cols;
	int height=tmp.rows;

	for(int i=0;i<NTIMES;i++){
		matchTemplate( img, tmp, result, TM_CCOEFF_NORMED);
		/// Localizing the best match with minMaxLoc
	  	double minVal, maxVal;
	  	Point minLoc, maxLoc;
	  	minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
	  	top_left= maxLoc;
	}
	cerr<<"matched at ( "<<top_left.x<<", "<<top_left.y<<" ) to ( "<<(top_left.x+width)<<" , "<<(top_left.y+height)<<" )."<<endl;
	return 0;
}
```
### 3. I/O処理
```python
import sys
import numpy as np
import cv2

NTIMES=1000

if __name__ == '__main__':
	if len(sys.argv)!=2:
		print "usage filename"
		sys.exit(1)

	for i in range(0,NTIMES):
		img = cv2.imread(sys.argv[1])
		cv2.imwrite("pout.jpg",img)
```
```cpp
#include <iostream>
#include <vector>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define NTIMES 1000

int main(int argc, char* argv[]){
	Mat img;

	if(argc!=2){
		cerr<<"usage filename"<<endl;
		exit(1);
	}
	for(int i=0;i<NTIMES;i++){
		img=imread(argv[1]);
		imwrite("out.jpg",img);
	}
}
```
### 評価用シェル

```sh
#!/bin/bash

echo "launch gaussian fillter in python"
for i in `seq 1 10`
do
	echo `(time -p python bench_gaussian.py baboon.jpg ) 2>&1 | grep real`
done

echo "launch gaussian fillter in C++"
for i in `seq 1 10`
do
	echo `(time -p ./bench_gaussian baboon.jpg ) 2>&1 | grep real`
done

echo "-----"

echo "launch matching in python"
for i in `seq 1 10`
do
	echo `(time -p python bench_matching.py baboon.jpg baboon_tmp.jpg) 2>&1 | grep real`
done

echo "launch matching in C++"
for i in `seq 1 10`
do
	echo `(time -p ./bench_matching baboon.jpg baboon_tmp.jpg) 2>&1 | grep real`
done

echo "-----"

echo "launch io in python"
for i in `seq 1 10`
do
	echo `(time -p python bench_io.py baboon.jpg) 2>&1 | grep real`
done

echo "launch io in C++"
for i in `seq 1 10`
do
	echo `(time -p ./bench_io baboon.jpg) 2>&1 | grep real`
done

echo "-----"
```
