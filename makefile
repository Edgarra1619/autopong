CCFLAGS = -Wall -Wextra -O
OBJECTS = ./bin/game.o ./bin/main.o ./bin/render.o


all: autopongo

autopongo: $(OBJECTS)
	clang $(CCFLAGS) $(OBJECTS) -lncurses -o autopongo

$(OBJECTS) : ./bin/%.o : ./src/%.c
	clang $(CCFLAGS) ./src/$*.c -c -o $@

clean:
	rm $(OBJECTS) -f

re: clean autopongo
