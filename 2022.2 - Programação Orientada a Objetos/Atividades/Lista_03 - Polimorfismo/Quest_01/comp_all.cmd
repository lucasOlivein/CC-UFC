cd class/child_bidimencional/implementacao
g++ -c *.cpp
move *.o "../../../o"

cd ../../child_tridimencional/implementacao
g++ -c *.cpp
move *.o "../../../o"

cd ../../..

g++ -c *.cpp
move *.o o

cd o

g++ *.o -o run
move run.exe ".."
cd ..

