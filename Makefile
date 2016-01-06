# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguillon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 14:29:06 by mguillon          #+#    #+#              #
#    Updated: 2016/01/06 14:39:35 by mguillon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC = main.c \
	  mlx_init.c

MLX_DIR = ./mlx

MLX = $(MLX_DIR)/libmlx.a -I$(MLX_DIR) -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC := $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I libft/ -I includes/ -g

all: $(NAME)

$(NAME): $(SRC) Makefile includes/rtv1.h
	make -C libft/
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(SRC) -L libft/ -lft -lm $(MLX) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	make -C $(MLX_DIR) clean
	@rm -f $(NAME)

re: fclean all
