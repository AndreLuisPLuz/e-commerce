CC = gcc
CFLAGS = -Wall -Werror -O3

INCLUDES = include

BIN = bin/program.exe
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))


all: bin src obj $(BIN) $(OBJ)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDES) $^ -o $@

obj/filters.o: src/filters.c $(INCLUDES)/filters.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/structs.o: src/structs.c $(INCLUDES)/structs.h
	$(CC) $(CFLAGS) -c $< -o $@

obj/main.o: src/main.c
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	mkdir bin

src:
	mkdir src

obj:
	mkdir obj

include:
	mkdir include

run:
	$(BIN)

clean:
	del "obj/*"

.PHONY: all clean run