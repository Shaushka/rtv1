/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:59:10 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/27 13:37:57 by mguillon         ###   ########.fr       */
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

typedef struct	s_sphere
{
	t_vector			pos;
	float				radius;
	struct s_sphere		*next;
}				t_sphere;

typedef struct	s_cone
{
	t_vector			pos;
	float				rayon;
	float				hauteur;
	struct s_cone		*next;
}				t_cone;

typedef struct	s_cylinder
{
	t_vector			pos;
	float				rayon;
	float				hauteur;
	struct s_cylinder	*next;
}				t_cylinder;

typedef	struct	s_plane
{
	t_vector			pos;
	t_vector			normal;
	float				constant;
	struct s_plane		*next;
}				t_plane;

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
	t_sphere	*spheres;
	t_cone		*cones;
	t_cylinder	*cylinders;
	t_plane		*planes;
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
	t_cam		cam;
	t_light		*lights;
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
**	shapes.c
*/
void			add_sphere(t_env *e);
void			add_cylinder(t_env *e);
void			add_cone(t_env *e);
void			add_plane(t_env *e);

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
float			inter_sphere(t_cam cam, t_vector ray, t_sphere sphere);
t_vector		normal_sphere(t_sphere obj, t_vector ray, float inter);

/*
**	plane.c
*/
float			inter_plane(t_cam cam, t_vector ray, t_plane plane);

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

#endif
