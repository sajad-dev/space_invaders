#!/bin/bash

cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
make

args=("$@")
./SpaceInvaders "${args[@]}"
cd ..
