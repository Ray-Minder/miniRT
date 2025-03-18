NAME = minirt

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
OBJ_DIR = obj

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ./libraries/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

# Source files
SRCS = $(shell find $(SRC_DIR) -name '*.c')

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

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

.PHONY: all clean