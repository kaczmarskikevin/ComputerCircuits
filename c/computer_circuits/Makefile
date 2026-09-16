# Compiler settings
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -Iinclude

# Directories
SRCDIR  := src
OBJDIR  := obj
BINDIR  := bin

# Target executable name
TARGET  := $(BINDIR)/main_program

# 1. Find all .c files recursively under SRCDIR
SOURCES := $(shell find $(SRCDIR) -type f -name '*.c')

# 2. Generate object file paths inside OBJDIR corresponding to source files
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

# Compile C source files to object files recursively
# The mkdir command mirrors the source subdirectory tree structure under OBJDIR
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean