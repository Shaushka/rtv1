/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:59:10 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/29 20:43:44 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# define SCREEN_W		1280
# define SCREEN_H		960

# define MAX_VISION(h)		(3570 + sqrt((h)))
# define PI			3.14159265
# define RATIO		(PI / 180)

typedef	struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef	enum {SPHERE, PLANE, CYLINDER, CONE} t_type;

typedef	struct	s_object
{
	void				*next;
	t_type				type;
	t_color				color;
	t_vector			pos;
	t_vector			normal;//plan
	float				radius;//sphere cone cylindre
	float				height;//cone cylindre
	float				constant;//plan
}						t_object;

typedef struct		s_light
{
	t_vector		pos;
	t_vector		dir;
	t_color			color;
	float			intensity;
	struct s_light	*next;
}					t_light;

typedef struct	s_scene
{
	void		*l_obj;
	t_light		*light;
}				t_scene;

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	dir;
	t_vector	h;
	t_vector	d;
}				t_cam;

typedef struct	s_img
{
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			opp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx_init
{
	t_img		img;
	void		*mlx;
	void		*win;
}				t_mlx_init;

typedef struct	s_env
{
	t_mlx_init	mlx_init;
	t_scene		*scene;
	t_light		*lights;
	t_cam		cam;
}				t_env;

/*
**	main.c
*/
void			ft_initialize(t_env *e);

/*
**	initialization.c
*/
void			ft_exit(char *str, int n);
void			quit_and_free(t_env *e);
void			init_env(t_env *e);
int				expose_hook(t_env *e);
void			init_and_draw(t_env *e, char *av);
void			init_obj(t_object *node);

/*
**	ray_tracing.c
*/
void			ft_render(t_env *e);

/*
**	hook_functions.c
*/
int				expose_hook(t_env *e);
int				key_press_hook(int keycode, t_env *e);

/*
**	graphics_tools.c
*/
void			put_pixel_to_img(t_env *e, int addr, t_color color);
void			set_color_from_img(t_color *color, char *data, int addr);
void			set_color_from_rgb(t_color *color, int r, int g, int b);
void			get_true_color_value(t_color *color);
void			blend_color(t_color *c, t_color c1, t_color c2, double percent);

/*
**	----------> USER INPUT SYSTEM <-----
*/
/*
**	create_scene.c
*/
void			create_scene(t_env *e);

/*
**	add_shape.c
*/
void			input_sphere(t_env *e);
void			input_plane(t_env *e);
void			input_cylinder(t_env *e);
void			input_cone(t_env *e);

/*
**	assign_color.c
*/
void			color(t_color *color);
void			color_choice(t_color *color);

/*
**	create_object.c
*/
t_object		*create_object(t_env *e);

/*
**	infos_shapes.c
*/
void			radius(t_object *node);
void			height(t_object *node);
void			constant(t_object *node);
//int			count_objects(t_env *e);

/*
**	input_normal.c
*/
void			assign_normal(t_object *node, char *str);//static ?
void			normal(t_object *node);

/*
**	input_vectors_clean.c
*/
char			**remove_spaces(char *str, int i, char **clean);//static ?
void			separators(char *str);//static ?
char			*no_more_spaces(char *str);

/*
**	input_verification.c
*/
int				is_slashes_and_digits(char *str);//static ?
int				is_vector(char *str);//static ?
int				correct_input(char *str);

/*
**	input_position.c
*/
char			*cut_pos(char *str, int i);
int				check_values(char *str, int min, int max);
void			assign_pos(t_object *node, char *str);
void			position(t_object *node);

/*
**	----------> GEOMETRY <-----
*/
/*
**	trigo.c
*/
float			d_cos(float angle);
float			d_sin(float angle);
float			d_acos(float value);

/*
**>----------> INTERSECTION <-----
*/

/*
**	sphere.c
*/
t_object		set_sphere(t_vector pos,float radius);
float			inter_sphere(t_cam cam, t_vector ray, t_object sphere);
t_vector		normal_sphere(t_object obj, t_vector ray, float inter);

/*
**	plane.c
*/
t_object		set_plane(t_vector pos, t_vector normal);
float			inter_plane(t_cam cam, t_vector ray, t_object plane);

/*
**	light.c
*/
t_color			diffuse_light(t_light light, t_color color, t_vector normal, t_vector s_ray);
void			init_lights(t_env e);

/*
**	vector.c
*/
t_vector		set_vector(t_vector v, float x, float y, float z);
float			dotpro_vector(t_vector a, t_vector b);
float			norm_vector(t_vector v);
t_vector		unit_vector(t_vector v);
t_vector		add_vector(t_vector v, t_vector u);
t_vector		sub_vector(t_vector v, t_vector u);
t_vector		cross_vector(t_vector v, t_vector u);
t_vector		mult_vector(t_vector a, float m);
float			sq_vector(t_vector a);

#endif
