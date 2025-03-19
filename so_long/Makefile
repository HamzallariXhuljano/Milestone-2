# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/14 15:37:02 by xhamzall          #+#    #+#              #
#    Updated: 2025/03/19 21:16:39 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -lmlx -Lminilibx-linux -lXext -lX11 -lm -lbsd

INCLUDES = -I/usr/include -Iminilibx-linux -Ilibft -Iget_next_line -Iprintf

PRINTDIR = printf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

NAME = so_long
#NAME_BONUS = checker

GNL = get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c

SRCDIR = source/
SRC = so_long.c parsing_pt1.c window.c utils.c parsing_pt2.c parsing_pt3.c

#BONUSDIR = bonus/
#BONUS = bonus/checker.c

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GNL_OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o)))
#OBJECT_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

# Object checker
#BONUS_SRC =


all: $(MLX) $(NAME)

#bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJECTS) $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -o $(NAME) $(PRINT) $(LIBFT) $(MLX_FLAGS)

# Bonus
#$(NAME_BONUS): $(LIBFT) $(OBJECT_BONUS) $(GNL_OBJECTS) $(PRINT)
#	$(CC) $(CFLAGS) $(OBJECT_BONUS) $(GNL_OBJECTS) -o $(NAME_BONUS) $(PRINT) $(LIBFT)
#scaricare e compilare MiniLibix
$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)
	cd $(MLX_DIR) && make
# Libft compiling
$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR) --quiet

# Printf compiling
$(PRINT): $(PRINTDIR)
	@$(MAKE) -C $(PRINTDIR) --quiet

$(OBJ_DIR)/%.o: $(SRCDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# Bonus object
#$(OBJ_DIR)/%.o: $(BONUSDIR)%.c
#	mkdir -p $(OBJ_DIR)
#	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

# GNL
$(OBJ_DIR)/%.o: $(GNL)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTDIR)
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) clean -C $(MLX_DIR); fi
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTDIR)
	rm -rf $(NAME)
	rm -rf $(MLX_DIR)
re: fclean all

.PHONY: all bonus clean fclean re
