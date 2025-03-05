# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 15:39:35 by xhamzall          #+#    #+#              #
#    Updated: 2025/03/01 21:24:30 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -Ilibft -Iget_next_line -Iprintf

PRINTDIR = printf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

NAME = pipex
#NAME_BONUS = checker

GNL = get_next_line/
GNL_SRC = get_next_line.c get_next_line_utils.c

SRCDIR = source/
SRC = source/pipex.c

#BONUSDIR = bonus/
#BONUS = bonus/checker.c

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
GNL_OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(GNL_SRC:.c=.o)))
#OBJECT_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

# Object checker
#BONUS_SRC =


all: $(NAME)

#bonus: $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJECTS) $(GNL_OBJECTS) $(PRINT)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -o $(NAME) $(PRINT) $(LIBFT)

# Bonus
#$(NAME_BONUS): $(LIBFT) $(OBJECT_BONUS) $(GNL_OBJECTS) $(PRINT)
#	$(CC) $(CFLAGS) $(OBJECT_BONUS) $(GNL_OBJECTS) -o $(NAME_BONUS) $(PRINT) $(LIBFT)

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
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTDIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
