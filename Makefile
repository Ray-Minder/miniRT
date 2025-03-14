CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -Werror

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
TESTS_DIR = tests
BIN_DIR = bin

SRCS = $(shell find $(SRC_DIR) -name '*.c') # Automatically find all .c files in src/
TESTS = $(wildcard $(TESTS_DIR)/*.c) # Automatically find all .c test files
TEST_BINS = $(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TESTS)) # Convert test file names to bin names

all: $(BIN_DIR) $(TEST_BINS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null
	@echo "$(GREEN_LIGHT)Library libft created.$(RESET)"

# Rule to compile each test case
$(BIN_DIR)/%: $(TESTS_DIR)/%.c $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -lm 
# lm has to be placed a the end to link math library

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	@rm -rf $(BIN_DIR)
	@make -C $(LIBFT_DIR) clean >/dev/null

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null

re: clean all

# Run all tests
test: all
	@for test in $(TEST_BINS); do echo "Running $$test..."; $$test; echo ""; done