# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgras <mgras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 19:20:06 by mguirado          #+#    #+#              #
#    Updated: 2016/02/21 19:48:58 by mgras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------------------------------------------------------------------
# VARIABLES ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
# ----------------------------------------------------------------------------
NAME = rt

CC = gcc
CFLAGS += -Wall -Werror -Wextra -O3

SRC_PATH = ./src/
SRC_NAME = main_fork.c									\
		   graphics_tools.c								\
		   initialization.c								\
		   exit_and_quit.c								\
		   hook_functions.c								\
		   hook_functions_2.c							\
		   ray_tracing.c								\
		   sphere.c										\
		   debug.c										\
		   light.c										\
		   light_ambiant.c								\
		   light_specular.c								\
		   light_diffuse.c								\
		   light_reflection.c							\
		   refraction.c									\
		   vector.c										\
		   vector2.c									\
		   color.c										\
		   plane.c										\
		   cylinder.c									\
		   cone.c										\
		   premade_objects.c							\
		   texture.c									\
		   intersection.c								\
		   item_cut.c									\
		   render.c										\
		   interactive/add_shape.c 						\
		   interactive/assign_color.c					\
		   interactive/create_scene.c					\
		   interactive/create_object.c					\
		   interactive/infos_shapes.c					\
		   interactive/input_normal.c					\
		   interactive/input_vectors_clean.c			\
		   interactive/input_position.c					\
		   interactive/input_verification.c				\
		   parser.c										\
		   setter.c										\
		   keyring/ft_keyring_shapes.c					\
		   keyring/ft_keyring_apply.c					\
		   keyring/ft_keyring.c							\
		   keyring/ft_keyring_reset.c					\
		   keyring/ft_keyring_main_menu.c				\
		   keyring/ft_keyring_cam_interface.c			\
		   keyring/ft_keyring_cam_interface_2.c			\
		   keyring/ft_keyring_light_interface.c			\
		   keyring/ft_keyring_object_interface.c		\
		   keyring/ft_keyring_object_interface_2.c		\
		   keyring/ft_keyring_light_interface_cmd.c		\
		   keyring/ft_keyring_utility.c					\
		   keyring/ft_keyring_light_interface_2.c		\
		   keyring/ft_keyring_light_interface_3.c		\
		   keyring/ft_keyring_ui.c						\
		   keyring/ft_keyring_ui_2.c					\
		   keyring/ft_keyring_nape_generator.c			\
		   loading_bar.c								\
		   ft_texture_load.c							\
		   options_parser.c								\
		   options_parser_2.c							\
		   assign_pos_light.c							\
		   ft_free_utility.c							\
		   ft_free_utility_2.c							\
		   file_and_scene.c								\
		   get_instructions.c							\
		   recup_nodes.c								\
		   parse_checks.c								\
		   shall_i_reflect_and_refract.c				\
		   save.c										\

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
