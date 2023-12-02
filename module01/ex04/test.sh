#!/bin/bash

make

./replace "main.cpp" "string" "STRING" &&
sed 's/string/STRING/g' main.cpp | diff -s - main.cpp.replace; true &&
rm main.cpp.replace