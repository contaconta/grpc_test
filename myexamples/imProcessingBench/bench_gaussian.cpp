//Apply Gaussian Fillter

#include <iostream>
#include <vector>
#include <chrono>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


#define NTIMES 1000
#define KERNEL_LENGTH 5

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
	Mat img;
	double proccessingTime=0;
	if(argc!=2){
		cerr<<"usage filename"<<endl;
		exit(1);
	}
	img=imread(argv[1]);
	cout<<img<<endl;
	cerr<<"ch,dim"<<img.channels()<<", "<<img.dims<<std::endl;
	for(int i=0;i<NTIMES;i++){
		auto start=std::chrono::system_clock::now();
		GaussianBlur( img, img, Size( KERNEL_LENGTH, KERNEL_LENGTH ),0);
		auto end=std::chrono::system_clock::now();
		proccessingTime+=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	}
	imwrite("cfilterd.jpg",img);
	cerr<<"filter end"<<endl;
	cout<<"Time "<<proccessingTime<<"ms"<<std::endl;
	return 0;
}