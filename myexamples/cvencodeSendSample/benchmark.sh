#!/bin/bash

echo "detail launch time of gaussian fillter in python and C++ (using GRPC)"
for i in `seq 1 10`
do
	echo `(python bench_sample_cvgrpc_encode_client.py localhost baboon.jpg baboon_e.jpg )  | grep time`
done 

