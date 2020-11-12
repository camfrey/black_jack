# 10 points
# Define Make rules as follows:
# A default rule to compile a .c file into a .o file
# A rule for "all" to build the entire project into a program called "game"
# A rule for "clean" to remove all .o files


default: card.c
	cc -c card.c

all: card.o game.c
	cc -o game game.c card.o

clean: card.o game
	rm card.o; rm game
