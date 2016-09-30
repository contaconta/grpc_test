#include <iostream>
#include <memory>
#include <string>

#include <grpc++/grpc++.h>
#include "cpyhello.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Statuss;
//made from cpyhello.proto (compiled)
using cpyhello::CpyGreeter;
using cpyhello::GreeReq;
using cpyhello::GreeRes;

class cpyHelloService final : public CpyGreeter::Service
{
public:
	Status mySayHello(ServerContext* ctx, const GreeReq* req, GreeRes* res) override{
		int id=req->id();
		std::string name=req->name();
		std::cerr<<"gree from id "<<id<<", name "<<name<<" message is : "<<req->message()<<std::endl;
		res->set_host(myhostname);
		res->set_message("Thank you your greeting!!");
		return Status::OK;
	}
private:
	std::string myhostname="master_cpp";
	
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  cpyHelloService service;

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