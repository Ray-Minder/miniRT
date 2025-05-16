# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lprieri <lprieri@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2025/04/30 12:36:53 by lprieri       #+#    #+#                  #
#    Updated: 2025/04/30 12:36:53 by lprieri       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address -fsanitize=leak -g

INCLUDE_DIR = ./include
HEADER = $(INCLUDE_DIR)/libft.h

SRC_DIR = src
OBJ_DIR = obj
ASCII_DIR = $(SRC_DIR)/ascii
CONVERT_DIR = $(SRC_DIR)/convert
FREE_DIR = $(SRC_DIR)/free
LIST_DIR = $(SRC_DIR)/list
MEMORY_DIR = $(SRC_DIR)/memory
PUT_DIR = $(SRC_DIR)/put
STRING_DIR = $(SRC_DIR)/string

OBJ_ASCII_DIR = $(OBJ_DIR)/ascii
OBJ_CONVERT_DIR = $(OBJ_DIR)/convert
OBJ_FREE_DIR = $(OBJ_DIR)/free
OBJ_LIST_DIR = $(OBJ_DIR)/list
OBJ_MEMORY_DIR = $(OBJ_DIR)/memory
OBJ_PUT_DIR = $(OBJ_DIR)/put
OBJ_STRING_DIR = $(OBJ_DIR)/string


ASCII = ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		

CONVERT = ft_atoi.c			\
			ft_itoa.c		\
			ft_tolower.c	\
			ft_toupper.c	

FREE =	ft_free_2d.c		\
		ft_free_3d.c		\
		ft_free_n.c 		\
		ft_free.c 			

LIST = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

MEMORY = ft_bzero.c \
			ft_calloc.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c 

PUT = ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

STRING = ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c 

SRC = $(addprefix $(ASCII_DIR)/, $(ASCII)) \
	$(addprefix $(CONVERT_DIR)/, $(CONVERT)) \
	$(addprefix $(FREE_DIR)/, $(FREE)) \
	$(addprefix $(LIST_DIR)/, $(LIST)) \
	$(addprefix $(MEMORY_DIR)/, $(MEMORY)) \
	$(addprefix $(PUT_DIR)/, $(PUT)) \
	$(addprefix $(STRING_DIR)/, $(STRING))

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

OBJ_SUBDIRS = $(OBJ_ASCII_DIR) $(OBJ_CONVERT_DIR) $(OBJ_FREE_DIR) $(OBJ_LIST_DIR) \
              $(OBJ_MEMORY_DIR) $(OBJ_PUT_DIR) $(OBJ_STRING_DIR)

# ==================== RULES ====================

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUBDIRS)
	@echo "Building $@"
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_SUBDIRS):
	@mkdir -p $@

# Compile rules for each subdirectory
$(OBJ_ASCII_DIR)/%.o: $(ASCII_DIR)/%.c | $(OBJ_ASCII_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_CONVERT_DIR)/%.o: $(CONVERT_DIR)/%.c | $(OBJ_CONVERT_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_FREE_DIR)/%.o: $(FREE_DIR)/%.c | $(OBJ_FREE_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_LIST_DIR)/%.o: $(LIST_DIR)/%.c | $(OBJ_LIST_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_MEMORY_DIR)/%.o: $(MEMORY_DIR)/%.c | $(OBJ_MEMORY_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_PUT_DIR)/%.o: $(PUT_DIR)/%.c | $(OBJ_PUT_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(OBJ_STRING_DIR)/%.o: $(STRING_DIR)/%.c | $(OBJ_STRING_DIR)
	@$(CC) $(FLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

