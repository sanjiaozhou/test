#!/bin/bash

echo "start build code !"

rm -rf build

mkdir build

cd build

cmake ..

make 
