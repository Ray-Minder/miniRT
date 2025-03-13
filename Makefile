CC = cc
CFLAGS = -Iinclude -Wall -Wextra -Werror -g

SRC_DIR = src
TESTS_DIR = tests
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.c) \
		$(wildcard $(SRC_DIR)/**/*.c) # Automatically find all .c source files

TESTS = $(wildcard $(TESTS_DIR)/*.c) # Automatically find all .c test files
TEST_BINS = $(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TESTS)) # Convert test file names to bin names

all: $(BIN_DIR) $(TEST_BINS)

# Rule to compile each test case
$(BIN_DIR)/%: $(TESTS_DIR)/%.c $(SRCS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ $^ -lm ./libft/libft.a
# lm has to be flaced a the end to link math library

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)
	make -C ./libft fclean

re: clean all

# Run all tests
test: all
	@for test in $(TEST_BINS); do echo "Running $$test..."; $$test; echo ""; done