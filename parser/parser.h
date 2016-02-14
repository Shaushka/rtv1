#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"
# include "rtv1.h"

# define BUF_SIZE 10

typedef struct		s_node
{
	int		beg;
	char		type;
	struct s_node	*next;
}			t_node;

typedef struct 		s_parse
{
	char 		*name;
	int		win_h;
	int		win_w;
	int		cam_pos_x;
	int		cam_pos_y;
	int		cam_pos_z;
	int		cam_dir_x;
	int		cam_dir_y;
	int		cam_dir_z;
	t_node		*nodes;
	t_object	*obj;
}			t_parse;

void				open_file(char *file, t_parse *parse);
float				ft_atof(char *number);
void		assign_color(t_color *color, char *str);
t_object		*create_object();
void		assign_normal(t_object *node, char *str);
void			assign_pos(t_object *node, char *str);
int				check_values(char *str, int min, int max);
char			*cut_pos(char *str, int i);
void		separators(char *str);
char		*no_more_spaces(char *str);
char		**remove_spaces(char *str, int i, char **clean);
int				correct_input(char *str);
int				is_vector(char *str);
int				is_slashes_and_digits(char *str);
void			init_obj(t_object *node);
t_vector	set_vector(t_vector v, float x, float y, float z);
void	print_nodes(t_node *nodes);
void	print_result(t_parse *parse);
char	*recup_name(t_node *node, char *get, char c);
int	get_size(char *get, int i, char c);
void	set_object_type(char *name, t_object *obj);
void	set_object_param(char *value, char *data, t_object *obj);
void	error_in_parse(char *str);
void	get_instr(char *get, t_parse *parse);

#endif
