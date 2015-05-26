# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/26 11:29:55 by nschilli          #+#    #+#              #
#    Updated: 2015/05/26 11:31:19 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	scop

SRCDIR = srcs/

HDDIR = includes/

CFILES =	main.c \
			get_next_line.c \

SRC = $(addprefix $(SRCDIR), $(CFILES))

GCC = gcc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

%.o: %.c
	@echo -n .
	@$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re: fclean all

.PHONY: clean fclean re