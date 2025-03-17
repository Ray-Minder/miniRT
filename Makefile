NAME = minirt

CC = cc
CFLAGS = -Iinclude -Wall -Wextra -Werror

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ./libraries/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

SRC_DIR = src
TESTS_DIR = tests
BIN_DIR = bin

SRCS = $(shell find $(SRC_DIR) -name '*.c') # Automatically find all .c files in src/
TESTS = $(wildcard $(TESTS_DIR)/*.c) # Automatically find all .c test files
TEST_BINS = $(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TESTS)) # Convert test file names to bin names

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@echo $(BLUE)"Linking object files."$(RESET)
	@$(CC) $(FLAGS) $(OBJ) $(MLX42) -L $(LIBFT_DIR) -lft -ldl -lglfw -lm -o $(NAME)
	@echo $(GREEN)"Finished linking object files."$(RESET)

$(LIBFT):
	@echo $(GREEN)"Creating libft library."$(RESET)
	@$(MAKE) -C $(LIBFT_DIR) >/dev/null
	@echo $(GREEN)"Library libft created."$(RESET)

$(MLX42):
	@echo $(BLUE)"Building MLX42"$(RESET)
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build > /dev/null 2>&1
	@cmake --build $(MLX42_DIR)/build -j4 > /dev/null 2>&1
	@echo $(GREEN)"Finished creating MLX42 library."$(RESET)

# Rule to compile each test case
$(BIN_DIR)/%: $(TESTS_DIR)/%.c $(SRCS) $(LIBFT) $(MLX42)
#@echo $(MAGENTA)"Creating binaries."$(RESET)
	@$(CC) $(CFLAGS) -o $@ $^ $(MLX42) -L$(LIBFT_DIR) -lft -ldl -lglfw -lm 
# lm has to be placed a the end to link math library
#@echo $(GREEN)"Binaries created."$(RESET)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@rm -rf $(BIN_DIR)
	@make -C $(LIBFT_DIR) clean >/dev/null

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean >/dev/null
	@if [ -d $(MLX42_DIR)/build ]; then \
		$(RM) -r $(MLX42_DIR)/build; \
		echo $(WHITE)"Cleaned MLX42 library."$(RESET); \
	else \
		echo $(BLUE)"MLX42 is already removed."$(RESET); \
	fi
	@rm -f ./minirt

re: fclean all
	

# Run all tests
test: all $(BIN_DIR) $(TEST_BINS)
	@for test in $(TEST_BINS); do echo "Running $$test..."; $$test; echo ""; done

exe: all
	./minirt

# COLOURS
BOLD = "\e[1m"
BLACK = "\033[0;30m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
WHITE = "\033[0;37m"
RESET = "\033[0m"