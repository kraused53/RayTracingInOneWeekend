#!/bin/bash
cmake -B build
cmake --build build/
./build/raytracer > ./output/img.ppm