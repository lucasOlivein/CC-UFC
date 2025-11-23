@echo off
g++ -c *.cpp
g++ *.o -o program

mkdir exe

move *.o exe

