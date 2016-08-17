#!/bin/bash
echo "rm cmake cache begin..."

if [ -f ./cmake_install.cmake ]; then
	rm ./cmake_install.cmake
fi

if [ -d ./CMakeFiles/ ]; then
	rm -r ./CMakeFiles/
fi

if [ -f ./Makefile ]; then
	rm ./Makefile
fi

if [ -d ./CMakeCache/ ]; then
	rm -r ./CMakeCache/
fi

if [ -f ./CMakeCache.txt ]; then
	rm ./CMakeCache.txt
fi

if [ -f SortNumber ]; then
	rm ./SortNumber
fi

echo "rm cmake cache end..."
