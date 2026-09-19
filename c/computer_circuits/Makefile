CC     = gcc
CFLAGS = -Wall -Wextra -std=gnu99 -Iinclude

# Directories
SRC_DIR = src
TST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin

# Name of your main application executable
MAIN_BIN = $(BIN_DIR)/app

# Recursively find all .c files in src/
SRC_C = $(shell find $(SRC_DIR) -type f -name '*.c')

# Core library objects: Everything in src/ EXCEPT main.c
CORE_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/main.c, $(SRC_C)))

# Object file specifically for the main entry point
MAIN_OBJ = $(OBJ_DIR)/main.o

# Find all test .c files in tests/
TST_C = $(shell find $(TST_DIR) -type f -name '*.c')
# Map test files to individual executables in bin/
TST_BINS = $(patsubst $(TST_DIR)/%.c, $(BIN_DIR)/%, $(TST_C))

.PHONY: all test clean

# "all" now builds both your main application and your tests
all: $(MAIN_BIN) $(TST_BINS)

# Rule to build the main application (links core objects + main.o)
$(MAIN_BIN): $(MAIN_OBJ) $(CORE_OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to build test binaries (links core objects + specific test file, NO main.o)
$(BIN_DIR)/%: $(TST_DIR)/%.c $(CORE_OBJS) | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

# Pattern rule for compiling src/ files into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they do not exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Run all test executables
test: $(TST_BINS)
	@echo "Running tests..."
	@for t in $(TST_BINS); do \
		echo "--> Executing $$t"; \
		./$$t || exit 1; \
	done

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)