#!/bin/bash

DIR=$(pwd)

git clone https://github.com/AFLplusplus/AFLplusplus
cd AFLplusplus || exit
make distrib

cd "$DIR" || exit

mkdir -p build
mkdir -p in
mkdir -p out_s
mkdir -p out_r

echo 1 > in/1

make
