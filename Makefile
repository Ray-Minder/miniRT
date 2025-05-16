NAME = miniRT

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror 
#-g -fsanitize=address

SRC_DIR = src
OBJ_DIR = obj

LIBFT_DIR = libraries/libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX42_DIR = ./libraries/MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a

CAMERA_DIR = $(SRC_DIR)/camera
COLORS_DIR = $(SRC_DIR)/colors
ERRORS_DIR = $(SRC_DIR)/errors
GNL_DIR = $(SRC_DIR)/gnl
INIT_DIR = $(SRC_DIR)/init
INTERSECT_DIR = $(SRC_DIR)/intersect
LIGHTING_DIR = $(SRC_DIR)/lighting
MATRIX_DIR = $(SRC_DIR)/matrix
MLX_DIR = $(SRC_DIR)/mlx
PARSING_DIR = $(SRC_DIR)/parsing
RAYS_DIR = $(SRC_DIR)/rays
RENDERING_DIR = $(SRC_DIR)/rendering
TRANSFORMATIONS_DIR = $(SRC_DIR)/transformations
TUPLES_DIR = $(SRC_DIR)/tuples
UTILITIES_DIR = $(SRC_DIR)/utilities

# Source files

SRC_FILES = $(SRC_DIR)/main.c \
			$(CAMERA_SCRS) \
			$(COLORS_SRCS) \
			$(ERRORS_SRCS) \
			$(GNL_SRCS) \
			$(INIT_SRCS) \
			$(INTERSECT_SRCS) \
			$(LIGHTING_SRCS) \
			$(MATRIX_SRCS) \
			$(MLX_SRCS) \
			$(PARSING_SRCS) \
			$(RAYS_SRCS) \
			$(RENDERING_SRCS) \
			$(TRANSFORMATIONS_SRCS) \
			$(TUPLES_SRCS) \
			$(UTILITIES_SRCS)

CAMERA_SCRS = $(CAMERA_DIR)/camera.c \
				$(CAMERA_DIR)/ray_for_pixel.c \
				$(CAMERA_DIR)/view_transform.c

COLORS_SRCS = $(COLORS_DIR)/color_operations.c \
				$(COLORS_DIR)/colors.c

ERRORS_SRCS = $(ERRORS_DIR)/clean.c \
				$(ERRORS_DIR)/print_error.c

GNL_SRCS = $(GNL_DIR)/get_next_line_utils.c \
			$(GNL_DIR)/get_next_line.c

INIT_SRCS = $(INIT_DIR)/init_data.c

INTERSECT_SRCS = $(INTERSECT_DIR)/color_at.c \
				$(INTERSECT_DIR)/computations.c \
				$(INTERSECT_DIR)/cylinder_caps.c \
				$(INTERSECT_DIR)/cylinder_intersect.c \
				$(INTERSECT_DIR)/intersect_world.c \
				$(INTERSECT_DIR)/intersection_utils.c \
				$(INTERSECT_DIR)/intersections.c \
				$(INTERSECT_DIR)/sphere_intersect.c

LIGHTING_SRCS = $(LIGHTING_DIR)/lighting.c \
				$(LIGHTING_DIR)/shading.c

MATRIX_SRCS = $(MATRIX_DIR)/matrices.c \
				$(MATRIX_DIR)/matrix_operations_1.c \
				$(MATRIX_DIR)/matrix_operations_2.c \
				$(MATRIX_DIR)/matrix_utils.c
			
MLX_SRCS = $(MLX_DIR)/hooks.c

PARSING_SRCS = $(PARSING_DIR)/camera_matrix.c \
				$(PARSING_DIR)/cleanup.c \
				$(PARSING_DIR)/init_scene.c \
				$(PARSING_DIR)/linked_list.c \
				$(PARSING_DIR)/parse_cylinder.c \
				$(PARSING_DIR)/parse_doubles.c \
				$(PARSING_DIR)/parse_elements.c \
				$(PARSING_DIR)/parse_error.c \
				$(PARSING_DIR)/parse_objects.c \
				$(PARSING_DIR)/parse_uint8.c \
				$(PARSING_DIR)/parser.c \
				$(PARSING_DIR)/set_object_transforms.c \
				$(PARSING_DIR)/tuple_to_matrix.c \
				$(PARSING_DIR)/verify_filename.c

RAYS_SRCS = $(RAYS_DIR)/normals.c \
			$(RAYS_DIR)/ray.c \
			$(RAYS_DIR)/reflect.c \
			$(RAYS_DIR)/transform.c

RENDERING_SRCS = $(RENDERING_DIR)/render_scene.c

TRANSFORMATIONS_SRCS = $(TRANSFORMATIONS_DIR)/chain_transformations.c \
						$(TRANSFORMATIONS_DIR)/rotation.c \
						$(TRANSFORMATIONS_DIR)/scaling.c \
						$(TRANSFORMATIONS_DIR)/translation.c

TUPLES_SRCS = $(TUPLES_DIR)/tuples_advanced_operations.c \
				$(TUPLES_DIR)/tuples_basic_operations.c \
				$(TUPLES_DIR)/tuples_utils.c \
				$(TUPLES_DIR)/tuples.c

UTILITIES_SRCS = $(UTILITIES_DIR)/compare_doubles.c \
				$(UTILITIES_DIR)/degrees_to_radians.c

# Object files
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

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
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(OBJS:.o=.d)

# Clean up build files
clean:
	@rm -fdr $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean >/dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean >/dev/null
	@if [ -d $(MLX42_DIR)/build ]; then \
		$(RM) -r $(MLX42_DIR)/build; \
		echo $(WHITE)"Cleaned MLX42 library."$(RESET); \
	else \
		echo $(BLUE)"MLX42 is already removed."$(RESET); \
	fi

re: fclean $(NAME)

.PHONY: all clean