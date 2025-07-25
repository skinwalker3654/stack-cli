CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/main

SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/stack.c

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all run clean

