#!/bin/bash
ret=`(time -p python bench_gaussian.py baboon.jpg ) 2>&1 | grep real`
echo ${ret:6}

