NAME = minirt

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj
TESTS_DIR = tests
BIN_DIR = bin

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ./libraries/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

# Source files
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

TESTS = $(wildcard $(TESTS_DIR)/*.c) # Automatically find all .c test files
TEST_BINS = $(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TESTS)) # Convert test file names to bin names

# Default target
all: $(NAME)

$(LIBFT):
	@echo $(GREEN)"Creating libft library."$(RESET)
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null
	@echo $(GREEN)"Library libft created."$(RESET)

$(MLX42):
	@echo $(BLUE)"Building MLX42"$(RESET)
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build > /dev/null 2>&1
	@cmake --build $(MLX42_DIR)/build -j4 > /dev/null 2>&1
	@echo $(GREEN)"Finished creating MLX42 library."$(RESET)

# Link object files to create the executable
$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft -ldl -lglfw -lm

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile each test case
$(BIN_DIR)/%: $(TESTS_DIR)/%.c $(filter-out $(SRC_DIR)/main.c, $(SRCS)) $(LIBFT) $(MLX42)
#@echo $(MAGENTA)"Creating binaries."$(RESET)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX42) -L$(LIBFT_DIR) -lft -ldl -lglfw -lm

# Create bin directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Clean up build files
clean:
	@rm -fdr $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean >/dev/null

fclean: clean
	@rm -f $(NAME)
	@if [ -d $(MLX42_DIR)/build ]; then \
		$(RM) -r $(MLX42_DIR)/build; \
		echo $(WHITE)"Cleaned MLX42 library."$(RESET); \
	else \
		echo $(BLUE)"MLX42 is already removed."$(RESET); \
	fi

re: fclean $(NAME)

# Run all tests
test: all $(BIN_DIR) $(TEST_BINS)
	@for test in $(TEST_BINS); do echo "Running $$test..."; $$test; echo ""; done

.PHONY: all clean