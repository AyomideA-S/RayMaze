# Compiler
CC = gcc

# Compiler flags: warnings and optimization
# We excluded the -Werror -pedantic flags to allow for more flexible code that may not strictly adhere to all standards, which can be beneficial during development.
# -Iinclude tells the compiler to look in our local 'include' folder for our own headers
CFLAGS = -Wall -Wextra -O2 -Iinclude

# Linker flags: math library and SDL2 for Windows via MSYS2
LFLAGS = -lmingw32 -lSDL2main -lSDL2 -mwindows -lm

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/RayMaze.exe

# Default build target
all: $(TARGET)

# Rule to link objects into the final executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@ $(LFLAGS)

# Rule to compile .c files into .o object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rebuild everything from scratch
re: clean all

# Phony targets to prevent conflicts with files named 'clean' or 'all'
.PHONY: all clean re