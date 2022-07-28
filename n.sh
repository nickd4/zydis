#!/bin/sh
#cmake .
gcc -Iinclude -Idependencies/zycore/include -L. -o decoder decoder.c -lZydis
./decoder
