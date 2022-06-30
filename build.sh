#! /bin/bash

rm -R bin

mkdir bin

cd bin

conan install ../src

cmake ../src

make