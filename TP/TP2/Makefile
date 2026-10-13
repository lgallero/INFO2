# TP2 - Matriz dinamica | Informatica II
# Uso:
#   make        compila el proyecto -> ejecutable ./tp2
#   make run    compila y ejecuta
#   make clean  borra objetos y ejecutable

CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -g
SRC      = $(wildcard src/*.cpp)
OBJ      = $(SRC:.cpp=.o)
HDR      = $(wildcard include/*.h)
BIN      = tp2

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Si cambia cualquier .h de include/, se recompilan todos los .cpp
src/%.o: src/%.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all run clean
