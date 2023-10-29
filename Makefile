# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra

# Source file
SRC = rsa.c

# Executable name
TARGET = a

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up object files and the executable
clean:
	rm -f $(TARGET)

.PHONY: all clean

