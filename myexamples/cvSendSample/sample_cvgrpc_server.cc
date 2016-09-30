#include <iostream>
#include <memory>
#include <string>
#include <chrono>

#include <grpc++/grpc++.h>
#include "cvgrpc.grpc.pb.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#define KERNEL_LENGTH 5

using namespace cv;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using cvgrpc::CvGrpcService;
using cvgrpc::ImgCVMat;

class CvGrpcConverter{
public:
	static void deconvertfromMat(InputArray src, ImgCVMat* output){
		//google::protobuf::Arena arena;
		//output = google::protobuf::Arena::CreateMessage<ImgCVMat>(&arena);
		Mat srcmat = src.getMat();
		Size size = srcmat.size();
		int depth;
		switch(srcmat.type()){
			case CV_8UC1:
				depth=1;
				break;
			case CV_8UC3:
				depth=3;
				break;
		}
		MatConstIterator_<Vec3b> sit=srcmat.begin<Vec3b>();
		MatConstIterator_<Vec3b> send=srcmat.end<Vec3b>();

		for(auto it=sit; it!=send; ++it){
			output->add_iarray((uint32_t)(*it)[0]);
			output->add_iarray((uint32_t)(*it)[1]);
			output->add_iarray((uint32_t)(*it)[2]);
		}
		output->set_depth((uint32_t)depth);
		output->set_width((uint32_t)size.width);
		output->set_height((uint32_t)size.height);
	}

	static void converttoMat(OutputArray dst,const ImgCVMat* input){
		int vecsize=input->width() * input->height();
		int totalsize=input->depth() * vecsize;
		uint8_t matBaseData[totalsize];
		Mat matdst;

		uint8_t* ptr_mat=matBaseData;
		auto imgary=input->iarray();

		int count=0;
		for(auto it=imgary.begin();it!=imgary.end();++it){
			*ptr_mat=(uint8_t)*it;
			ptr_mat++;
			count++;
		}
		std::cerr<<"size of pbufiarray"<<sizeof(uint32_t)*count<<std::endl;

		if(input->depth()==3){
			matdst=Mat(input->width(), input->height(), CV_8UC3, matBaseData);
		}else{
			matdst=Mat(input->width(), input->height(), CV_8UC1, matBaseData);
		}
		matdst.copyTo(dst);
	}
};


class CVGrpcServer final : public CvGrpcService::Service
{
	public:
	Status convertGaussian (ServerContext* ctx, const ImgCVMat* req, ImgCVMat* res) override{
		// evaluation
		processCount++;
		auto start=std::chrono::system_clock::now();
		
		Mat img;
		CvGrpcConverter::converttoMat(img,req);
		//std::cerr<<"filter start"<<std::endl;
		GaussianBlur( img, img, Size( KERNEL_LENGTH, KERNEL_LENGTH ),0);
		//std::cerr<<"filter end"<<std::endl;
		CvGrpcConverter::deconvertfromMat(img,res);
		// evaluation
		auto end=std::chrono::system_clock::now();
		proccessingTime+=std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
		if(processCount>=NTIMES){
			std::cerr<<"Total proccessingTime : "<<proccessingTime/1000<<" s"<<std::endl;
			processCount=0;
		}
		return Status::OK;
	}
//evaluation
private:
	double proccessingTime=0;
	int processCount=0;
	const int NTIMES=100; 
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