#include <iostream>
#include <memory>
#include <string>
#include <chrono>

#include <grpc++/grpc++.h>
#include "cvgrpc_bin.grpc.pb.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "google/protobuf/arena.h"

#define KERNEL_LENGTH 5

using namespace cv;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using cvgrpc_bin::CvGrpcService;
using cvgrpc_bin::ImgCVMat;

class CvGrpcConverter{
public:
	static void deconvertfromMat(InputArray src, ImgCVMat* output){
		Mat srcmat = src.getMat();
		Size size = srcmat.size();
		int depth;
		switch(srcmat.type()){
			case CV_8UC1:
				depth = 1;
				break;
			case CV_8UC3:
				depth = 3;
				break;
		}
		std::vector<unsigned char> matvec;
		imencode(".jpg",srcmat,matvec);
		std::string buffer(reinterpret_cast<char*>(&matvec[0]), matvec.size());
		output -> set_iarray(buffer);
		output -> set_depth((uint32_t)depth);
		output -> set_width((uint32_t)size.width);
		output -> set_height((uint32_t)size.height);
	}

	
	static Mat converttoMat(const ImgCVMat* input){
		int vecsize=input -> width() * input -> height();
		int totalsize=input -> depth() * vecsize;
		std::vector<char> matvec(input -> iarray().c_str(), input -> iarray().c_str()+input->iarray().size());
  		return cv::imdecode(matvec, -1);
	}
};


class CVGrpcServer final : public CvGrpcService::Service
{
	public:
	Status convertGaussian (ServerContext* ctx, const ImgCVMat* req, ImgCVMat* res) override{
		Mat img;

		processCount++;
		auto start = std::chrono::system_clock::now();
		img = CvGrpcConverter::converttoMat(req);
		auto end = std::chrono::system_clock::now();
		convertTime += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
		
		//std::cerr<<"filter start"<<std::endl;
		start = std::chrono::system_clock::now();
		GaussianBlur( img, img, Size( KERNEL_LENGTH, KERNEL_LENGTH ),0);
		end = std::chrono::system_clock::now();
		proccessingTime += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
		//std::cerr<<"filter end"<<std::endl;

		start = std::chrono::system_clock::now();
		CvGrpcConverter::deconvertfromMat(img,res);
		end = std::chrono::system_clock::now();
		deconvertTime += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
		// evaluation
		if(processCount >= NTIMES){
			std::cerr << "Total gaussian Time : " << proccessingTime / 1000 << " s"<<
				" Total convert time : " << convertTime / 1000 << " s" <<
				" Total deconvert time : " << deconvertTime / 1000 << " s" <<
				std::endl;
			processCount = 0;
			proccessingTime = 0;
			convertTime = 0;
			deconvertTime = 0;
		}
		return Status::OK;
	}
//evaluation
private:
	double proccessingTime = 0, convertTime = 0, deconvertTime = 0;
	int processCount = 0;
	const int NTIMES = 100; 
};


void RunServer() {
  std::string server_address("0.0.0.0:50051");
  CVGrpcServer service;
  ServerBuilder builder;

  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}