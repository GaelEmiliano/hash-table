# Compiler name
CC = gcc

# Directories
SRC_DIR = src

# Source files
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/hash_table.c

MAIN_EXEC = main

# The flags
CFLAGS = -Wall -g

# Compile hash_table
$(MAIN_EXEC): $(SRC_FILES)
	$(CC) $(CFLAGS) -o $(MAIN_EXEC) $(SRC_FILES)

# Clean compiled files
clean:
	rm -f $(MAIN_EXEC)

.PHONY: all clean
