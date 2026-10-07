SRC_DIR  := src
INC_DIR  := include
BIN_DIR  := bin
BUILD_DIR := build

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra
CPPFLAGS += -I$(INC_DIR)

TARGET := $(BIN_DIR)/programa
SRC    := $(wildcard $(SRC_DIR)/*.cpp)
OBJ    := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
