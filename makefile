CCFLAGS = -Wall -Wextra -g -lncurses

all:
	clang $(CCFLAGS) ./src/game.c ./src/main.c
