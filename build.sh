#!/usr/bin/env bash
make
find ./a_out/ -name "*.o" -type f -exec cp {} ./out \;
make link
make run
find ./a_out/ -name "*.o" -type f -delete
make clean