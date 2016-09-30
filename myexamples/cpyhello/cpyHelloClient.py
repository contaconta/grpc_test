from __future__ import print_function

import grpc
import cpyhello_pb2

def run():
	channel = grpc.insecure_channel('localhost:50051')
	#{ServiceName}Stub
	stub=cpyhello_pb2.CpyGreeterStub(channel)
	#stub.{rpc method name()}
	res = stub.mySayHello(cpyhello_pb2.GreeReq(id=1,name="client1",message="this is test"))
	print("message received : " +res.message)


if __name__ == '__main__':
  run()