#!/bin/bash

version=$(cat config/compile_version_base)
suffix=$(cat config/compile_version_suffix)
suffix=$(($suffix+1))

echo "[$(date)] ++ Compilation de 'build/release-$version.$suffix.exe' ..." >> logs/compile

g++ src/main.cpp src/classes/*/*.cpp -o build/release-$version.$suffix.exe 

git add logs/compile > /dev/null 2> /dev/null
git commit -m "[AUTO]Compilation de 'build/release-$version.$suffix.exe' ..." > /dev/null 2> /dev/null
git push > /dev/null 2> /dev/null
