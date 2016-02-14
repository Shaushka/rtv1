NAME = parser

CFLAGS = -Wall -Wextra -Werror 
INCLUDE = -I ./
SRC_PATH = ./
OBJ_PATH = ./
SRC_F =	main.c	\
	atof.c	\
	attributes.c	\
	debug.c	\
	setter.c	\
	parser.c

OBJ_F = $(SRC_F:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_F))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_F))

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ_F) ./libft/libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	gcc -o $@ -c $< $(CFLAGS) $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
