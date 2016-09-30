//Template Matching

#include <iostream>
#include <vector>
#include <chrono>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#define NTIMES 1000

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
	Mat img,tmp,result;
	Point top_left;
	double proccessingTime=0;
	if(argc!=3){
		cerr<<"usage imgfilename tmpfilename"<<endl;
		exit(1);
	}

	img=imread(argv[1]);
	tmp=imread(argv[2]);
	int width=tmp.cols;
	int height=tmp.rows;

	for(int i=0;i<NTIMES;i++){
		auto start=std::chrono::system_clock::now();
		matchTemplate( img, tmp, result, TM_CCOEFF_NORMED);
		auto end=std::chrono::system_clock::now();
		proccessingTime+=std::chrono::duration_cast<std::chrono::milliseconds>
		/// Localizing the best match with minMaxLoc
	  	double minVal, maxVal; 
	  	Point minLoc, maxLoc;
	  	minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, Mat() );
	  	top_left= maxLoc;
	}
	cerr<<"matched at ( "<<top_left.x<<", "<<top_left.y<<" ) to ( "<<(top_left.x+width)<<" , "<<(top_left.y+height)<<" )."<<endl;
	cout<<"Time "<<proccessingTime<<"ms"<<std::endl;
	return 0;
}