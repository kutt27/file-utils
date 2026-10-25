CC ?= gcc
CFLAGS ?= -Wall -Wextra -Wpedantic -Werror -std=c11 -02 -Iinclude
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

COMMON_SRC = $(SRC_DIR)/common.c
COMMON_OBJ = $(SRC_DIR)/common.o

TARGETS = $(BIN_DIR)/my_cat

.PHONY: all clean

all: $(BIN_DIR) $(TARGETS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(COMMON_OBJ): $(COMMON_SRC) $(INCLUDE_DIR)/common.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR)/my_cat: $(SRC_DIR)/cat.c $(COMMON_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BIN_DIR) $(SRC_DIR)/*.o
