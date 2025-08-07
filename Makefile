#compiler
CC = gcc

#directories
SRC_DIR = src
BIN_DIR = bin

#target
TARGET = $(BIN_DIR)/main

#source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/stack.c 

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	@echo "compiling the program..."
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@

run: all
	@echo "running the program..."
	./$(TARGET)

clean:
	@echo "deleting the bin folder..."
	rm -rf $(BIN_DIR)

.PHONY: all run clean

