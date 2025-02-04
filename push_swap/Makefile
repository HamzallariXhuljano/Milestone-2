# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 16:59:55 by xhamzall          #+#    #+#              #
#    Updated: 2025/02/04 17:06:48 by xhamzall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -Ilibft -Iprintf

PRINTDIR = printf/
PRINT = $(PRINTDIR)libftprintf.a

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

NAME = push_swap

SRCDIR = operations/
SRC =

OBJ_DIR = obj

OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)


#normal program
$(NAME):  $(LIBFT) $(OBJECTS)  $(PRINT)
	$(CC) $(CFLAGS) $(OBJECTS) -o  $(NAME) $(PRINT) $(LIBFT)

#Libft compiling
$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR) --quiet

#PRINTF compiling
$(PRINT): $(PRINTDIR)
	@$(MAKE) -C $(PRINTDIR) --quiet

#Object files
$(OBJ_DIR)/%.o: $(SRCDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)


clean:
		@$(MAKE) clean -C $(LIBFTDIR)
		@$(MAKE) clean -C $(PRINTDIR)
		rm -rf $(OBJ_DIR)

fclean: clean
		@$(MAKE) fclean -C $(LIBFTDIR)
		@$(MAKE) fclean -C $(PRINTDIR)
		rm -rf -C $(OBJ_DIR)
re: fclean all

.PHONY: all  bonus clean fclean re
