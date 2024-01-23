#! /bin/bash

rm -R bin

mkdir bin

cd bin

conan install ..

cmake ..

make