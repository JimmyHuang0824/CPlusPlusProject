#!/bin/bash
echo "rm cmake cache begin..."

if [ -f ./Makefile ]; then
	make clean
	rm ./Makefile
fi

if [ -f ./cmake_install.cmake ]; then
	rm ./cmake_install.cmake
fi

if [ -d ./CMakeFiles/ ]; then
	rm -rf ./CMakeFiles/
fi

if [ -d ./CMakeCache/ ]; then
	rm -rf ./CMakeCache/
fi

if [ -f ./CMakeCache.txt ]; then
	rm ./CMakeCache.txt
fi

echo "rm cmake cache end..."
