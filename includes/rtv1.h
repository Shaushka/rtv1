/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:59:10 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/13 10:49:32 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
#define FOV 90
#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
typedef	struct			s_vector
{
	float				x;
	float				y;
	float				z;
}						t_vector;

typedef struct 			s_sphere
{
	t_vector			pos;
	int					rayon;
	struct s_sphere		*next;
}						t_sphere;

typedef struct 			s_cone
{
	t_vector			pos;
	float				rayon;
	float				hauteur;
	struct s_cone		*next;
}						t_cone;

typedef struct 			s_cylindre
{
	t_vector			pos;
	float				rayon;
	float				hauteur;
	struct s_cylindre	*next;
}						t_cylindre;

typedef	struct			s_plan
{
	t_vector			pos;
	struct s_plan		*next;
}						t_plan;

typedef struct			s_scene
{
	t_sphere			*spheres;
	t_cone				*cones;
	t_cylindre			*cylindres;
	t_plan				*plans;
}						t_scene;


//might add shine to the color
/*typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;
*/
typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	t_scene*		scene;//tableau de listes chainees
}					t_env;

void		ft_initialize(t_env *e);

/*
void		new_image(t_env *e);
int			main(int argc, char **argv);
int			key_hook(int keycode, t_env *e);
void		ft_render(t_env *e);
t_color		check_collide(t_env e, ray);
*/
//---------------USER INPUT SYSTEM---------------

//creates lists depending on the shape entered
void		create_scene(t_env *e);
void		ft_sphere(t_env *e);
void		ft_cylindre(t_env *e);
void		ft_cone(t_env *e);
void		ft_plan(t_env *e);
//---------------GEOMETRY---------------

//trigo in degree | you can use radian with regular cos/sin/acos
/*float		d_cos(float angle);
float		d_sin(float angle);
float		d_acos(float value);

//vector
float		dotproduct(t_vector a, t_vector b);
float		norm_vector(t_vector v);
t_vector	unit_vector(t_vector v);
t_vector	add_vector(t_vector v, t_vector u);
t_vector	sub_vector(t_vector v, t_vector u);
t_vector	cross_vector(t_vector v, t_vector u);*/

#endif
