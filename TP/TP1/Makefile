# TP1 - Archivos cruzados | Informatica II
# Uso:
#   make        compila el proyecto -> ejecutable ./tp1
#   make run    compila y ejecuta
#   make clean  borra objetos y ejecutable

CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -Iinclude
SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)
BIN     = tp1

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all run clean
