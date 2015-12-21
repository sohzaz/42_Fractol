# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbreton <dbreton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/25 07:46:46 by dbreton           #+#    #+#              #
#    Updated: 2015/12/21 13:47:23 by dbreton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 
OS = $(shell uname)
CFLAGS = -Wall -Wextra -Werror -O2 
SRC = main.c draw_tools.c win_draw.c win_init.c win_handlers.c julia.c 
ifeq ($(OS), Darwin) 
	MLX = minlibx
	MFLAGS = -framework OpenGL -framework AppKit -lmlx -lm
else ifeq ($(OS), Linux)
	MLX = minlibx_X11
	MFLAGS = -lmlx -lXext -lX11 -lm
endif


OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C $(MLX)
	gcc $(CFLAGS) -c $(SRC)
	gcc $(CFLAGS) -L $(MLX) $(OBJ) -o $(NAME) $(MFLAGS)

all : $(NAME)

clean :
	make -C $(MLX) clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
