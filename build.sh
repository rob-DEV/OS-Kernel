#!/usr/bin/env bash
make
find . -name "*.o" -type f -exec cp {} ./out \;
make link
make run
find . -name "*.o" -type f -delete
make clean