#!/bin/bash

echo "launch gaussian fillter in only python"
for i in `seq 1 10`
do
	echo `(time -p python bench_gaussian.py baboon.jpg ) 2>&1 | grep real`
done 
echo "-----"
echo "launch gaussian fillter in python and C++ (using GRPC)"
for i in `seq 1 10`
do
	echo `(time -p python sample_cvgrpc_encode_client.py localhost baboon.jpg baboon_g.jpg ) 2>&1 | grep real`
done 

