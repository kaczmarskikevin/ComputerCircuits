CC     = gcc
CFLAGS = -Wall -Wextra -std=gnu99 -Iinclude

# Directories
SRC_DIR = src
TST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin

# Recursively find all .c files in src/
SRC_C = $(shell find $(SRC_DIR) -type f -name '*.c')
# Map source files to object files in obj/
SRC_OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_C))

# Find all test .c files in test/
TST_C = $(shell find $(TST_DIR) -type f -name '*.c')
# Map test files to executables in bin/
TST_BINS = $(patsubst $(TST_DIR)/%.c, $(BIN_DIR)/%, $(TST_C))

.PHONY: all test clean

all: $(TST_BINS)

# Compile tests, linking all core src object files (excluding any main() in src if applicable)
$(BIN_DIR)/%: $(TST_DIR)/%.c $(SRC_OBJS) | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

# Pattern rule for recursive compilation of src/ files into obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they do not exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

test: all
	@echo "Running tests..."
	@for t in $(TST_BINS); do \
		echo "--> Executing $$t"; \
		./$$t || exit 1; \
	done

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)