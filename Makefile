# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:03:12 by pecampos          #+#    #+#              #
#    Updated: 2023/08/07 11:29:44 by pecampos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

SRC = main.c ft_movement.c check.c check_utils.c map_init.c ft_itoa.c comprobar.c ft_load.c utils.c

OBJ = $(SRC:.c=.o)

RM = rm -f

CC = gcc

FLAGS = -Wall -Werror -Wextra

INCLUDE = -lglfw -L /Users/$$USER/.brew/opt/glfw/lib

MLX = MLX42/libmlx42.a


LIBFT = libft/libft.a

all:			$(NAME)
				$(CC) $(FLAGS) main.c $(NAME) $(LIBFT) $(MLX) $(INCLUDE) -o so_long
				
$(NAME):  		$(OBJ)
				cd libft && make all
				cd MLX42 && make all				
				$(CC) $(FLAGS) -c $(SRC)
				ar rcs $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME) so_long

exe: all
	@./$(NAME)
	
re:				fclean $(NAME)
	
run:
		./so_long