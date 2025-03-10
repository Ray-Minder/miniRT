CC = cc
CFLAGS = -Iinclude -Wall -Wextra -Werror

SRC_DIR = src
TESTS_DIR = tests
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c) # Automatically find all .c files in src/
TESTS = $(wildcard $(TESTS_DIR)/*.c) # Automatically find all .c test files
TEST_BINS = $(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TESTS)) # Convert test file names to bin names

all: $(BIN_DIR) $(TEST_BINS)

# Rule to compile each test case
$(BIN_DIR)/%: $(TESTS_DIR)/%.c $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ -lm 
# lm has to be flaced a the end to link math library

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

re: clean all

# Run all tests
test: all
	@for test in $(TEST_BINS); do echo "Running $$test..."; $$test; echo ""; done