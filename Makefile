# CC specifies the compiler to be used
CC = gcc

# CFLAGS specifies your compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic -O2 `sdl2-config --cflags`
# IFLAGS specifies the include flags
IFLAGS = -I include
# LFLAGS specifies the linker flags
LFLAGS = `sdl2-config --libs`

# SRC specifies the source files
SRC = src
# INC specifies the include directory
INC = include
# OBJ specifies the object files
OBJ = obj
# BIN specifies the binary files
BIN = bin

# A list of all the source files in SRC
SOURCES = $(wildcard $(SRC)/*.c)
# A list of corresponding object files for each source file
OBJECTS = $(SOURCES:$(SRC)/%.c=$(OBJ)/%.o)

# NAME specifies the name of our exectuable
NAME = RayMaze
# The name and location of the final executable
TARGET = $(BIN)/$(NAME)

# This rule builds our executable
# Makefile should not compile if the header file main.h is missing
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJECTS)
	mkdir -p $(BIN)
	$(CC) $(OBJECTS) -o $@ $(LFLAGS)

# Compile source files into object files
$(OBJ)/%.o: $(SRC)/%.c
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# This rule deletes all Emacs and Vim temporary files along with the executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# This rule forces recompilation of all source files
re: clean all

# Makefile should work even if there is a file in the folder
# that has the same name as rule
.PHONY: all clean re
