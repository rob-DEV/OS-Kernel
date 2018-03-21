#!/usr/bin/env bash
make
find . -name "*.o" -type f -exec cp {} ./out \;
make link
make run
make clean