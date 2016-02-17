# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgras <mgras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/14 20:31:10 by agadiffe          #+#    #+#              #
#    Updated: 2016/02/17 17:48:49 by mgras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# **************************************************************************** #

# ----------------------------------------------------------------------------
# VARIABLES ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
# ----------------------------------------------------------------------------
NAME = rtv1

CC = gcc
CFLAGS += -Wall -Werror -Wextra -g

SRC_PATH = ./src/
SRC_NAME = main.c								\
		   graphics_tools.c						\
		   initialization.c						\
		   exit_and_quit.c						\
		   hook_functions.c						\
		   ray_tracing.c						\
		   sphere.c								\
		   light.c								\
		   light_ambiant.c						\
		   light_reflection.c					\
		   light_specular.c						\
		   light_diffuse.c						\
		   vector.c								\
		   vector2.c							\
		   color.c								\
		   plane.c								\
		   cylinder.c							\
		   cone.c								\
		   premade_objects.c					\
		   texture.c							\
		   interactive/add_shape.c 				\
		   interactive/assign_color.c			\
		   interactive/create_scene.c			\
		   interactive/create_object.c			\
		   interactive/infos_shapes.c			\
		   interactive/input_normal.c			\
		   interactive/input_vectors_clean.c	\
		   interactive/input_position.c			\
		   interactive/input_verification.c		\
		   atof.c								\
		   debug.c								\
		   parser.c								\
		   setter.c								\
		   ft_keyring_shapes.c					\
		   ft_keyring_apply.c					\
		   ft_keyring.c							\
		   ft_keyring_reset.c					\
		   ft_keyring_main_menu.c				\
		   ft_keyring_cam_interface.c			\
		   ft_keyring_cam_interface_2.c			\
		   loading_bar.c						\

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC_PATH = ./includes/
INC = $(addprefix -I,$(INC_PATH))

LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a
LIBFT_INC_PATH = ./libft/includes/
LIBFT = $(addprefix -L,$(LIBFT_PATH))
LIBFT_INC = $(addprefix -I,$(LIBFT_INC_PATH))

LIBMLX_PATH = ./libmlx/
LIBMLX_NAME = libmlx.a
LIBMLX_INC_PATH = ./libmlx/includes/
LIBMLX = $(addprefix -L,$(LIBMLX_PATH))
LIBMLX_INC = $(addprefix -I,$(LIBMLX_INC_PATH))

LIBMLX_COMPILE_PATH = ./minilibx_macos/
LIBMLX_COMPILE_HEADERS = $(LIBMLX_COMPILE_PATH)mlx.h \
						 $(LIBMLX_COMPILE_PATH)mlx_int.h \
						 $(LIBMLX_COMPILE_PATH)mlx_new_window.h

# ----------------------------------------------------------------------------
# MISC |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
# ----------------------------------------------------------------------------
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBMLX_INC) $(INC) -o $@ -c $<

# ----------------------------------------------------------------------------
# RULES ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
# ----------------------------------------------------------------------------
all: $(NAME)

$(NAME): minilibx $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) -lft $(LIBMLX) -lmlx -framework OpenGL -framework Appkit -framework OpenCL

$(LIBFT_PATH)$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_PATH)

minilibx:
	@$(MAKE) -C $(LIBMLX_COMPILE_PATH)
	@mkdir -p $(LIBMLX_INC_PATH)
	@cp $(LIBMLX_COMPILE_HEADERS) $(LIBMLX_INC_PATH)
	@cp $(LIBMLX_COMPILE_PATH)$(LIBMLX_NAME) $(LIBMLX_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(LIBMLX_COMPILE_PATH) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@rm -rf $(LIBMLX_PATH)

re: fclean all

.PHONY: all clean fclean re minilibx $(LIBFT_PATH)$(LIBFT_NAME)
