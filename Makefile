# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/25 07:46:46 by dbreton           #+#    #+#              #
#    Updated: 2015/10/26 11:38:01 by dbreton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 
OS = $(shell uname)
CFLAGS = -Wall -Wextra -Werror
SRC = main.c draw_tools.c win_draw.c win_init.c 
ifeq ($(OS), Darwin) 
	MLX = minlibx
	MFLAGS = -framework OpenGL -framework AppKit -lmlx -lft -lm
else ifeq ($(OS), Linux)
	MLX = minlibx_X11
	MFLAGS = -lmlx -lXext -lX11 -lm -lft
endif


OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C $(MLX)
	make -C libft
	gcc $(CFLAGS) -I libft/includes -c $(SRC)
	gcc $(CFLAGS) -L libft $(OBJ) -o $(NAME) $(MFLAGS)

all : $(NAME)

clean :
	make -C libft clean
	make -C $(MLX) clean
	rm -f $(OBJ)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
