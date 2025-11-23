LIBRARIES = -lncurses

all : 
	gcc -c calcgame.c 
	gcc game.c calcgame.o -o game.o $(LIBRARIES) && ./game.o
	rm -rf *.o