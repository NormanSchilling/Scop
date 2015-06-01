# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/26 11:29:55 by nschilli          #+#    #+#              #
#    Updated: 2015/06/01 15:11:04 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	scop

SRCDIR = srcs/

HDDIR = -I includes/

HDDIR += -I ~/.brew/include/

CFILES =	main.c \
			get_next_line.c \
			opengl.c \
			utils.c \
			program.c \
			matrice.c \
			matrice_rotate.c \
			matrice_multiplication.c \
			parser.c \
			list_vertex.c \

SRC = $(addprefix $(SRCDIR), $(CFILES))

GCC = gcc

OBJ = $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -O3 -g

LIBOPENGL =	-L ~/.brew/lib/ -lglfw3 -framework OpenGL

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a $(LIBOPENGL)
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

%.o: %.c
	@echo -n .
	@$(GCC) $(CFLAGS) -c -o $@ $^ $(HDDIR)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"

re: fclean all

.PHONY: clean fclean re
