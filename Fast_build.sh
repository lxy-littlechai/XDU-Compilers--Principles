#!/bin/bash 
mkdir "build"
cd "build"
cmake ..
make .
make install
cd ..
rm -rf "build"