#!/bin/bash

mkdir -p build
cd build || exit

cmake ..
cmake --build .