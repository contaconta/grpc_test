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

