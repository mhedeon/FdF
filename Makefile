# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/26 17:25:08 by mhedeon           #+#    #+#              #
#    Updated: 2018/07/03 17:14:52 by mhedeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c map.c \
		draw_line.c draw_map.c \
		rotation.c other.c \
		init.c error.c key.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) -c $(SRC)
	@gcc -g -o $(NAME) $(OBJ) -L ./libft -lft -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@gcc $(FLAGS) -c $< -I $@
	
clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all
	@make -C libft re