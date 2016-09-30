#include <iostream>
#include <vector>
#include <chrono>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define NTIMES 1000

int main(int argc, char* argv[]){
	Mat img;
	double proccessingTime=0;
	if(argc!=2){
		cerr<<"usage filename"<<endl;
		exit(1);
	}
	for(int i=0;i<NTIMES;i++){
		auto start=std::chrono::system_clock::now();
		img=imread(argv[1]);
		imwrite("out.jpg",img);
		auto end=std::chrono::system_clock::now();
		proccessingTime+=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
	}
	cout<<"Time "<<proccessingTime<<"ms"<<std::endl;
}
	