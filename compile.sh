#!/bin/bash

version=$(cat config/compile_version_base)
suffix=$(cat config/compile_version_suffix)
suffix=$(($suffix+1))

echo "Compilation de 'build/release-$version.$suffix.exe' ..."

gcc src/main.cpp src/classes/*/*.cpp -o build/release-$version.$suffix.exe

git add * > /dev/null 2> /dev/null
git commit -m "[AUTO]Compilation de 'build/release-$version.$suffix.exe' ..." > /dev/null 2> /dev/null
git push > /dev/null 2> /dev/null
