@echo off
g++ -c *.cpp
g++ *.o -o prog

mkdir exe
move *.o exe

