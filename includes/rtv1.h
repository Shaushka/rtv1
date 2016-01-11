/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:59:10 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/11 19:07:10 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define HFOV 2 * atan(0.5 * WIN_H / 20)
# define WFOV 2 * atan(0.5 * WIN_W / 20)
#include <mlx.h>
#include <math.h>
#include "libft.h"

typedef struct		t_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
}					s_env;

typedef	struct		t_vector
{
	float			x;
	float			y;
	float			z;
}					s_vector;

typedef struct 		t_sphere
{
	s_vector		pos;
	int				rayon;
}					s_sphere;

typedef struct 		t_cone
{
	s_vector		pos;
	float			rayon;	
	float			hauteur;
}					s_cone;

typedef struct 		t_cylindre
{
	s_vector		pos;
	float			rayon;	
	float			hauteur;
}					s_cylindre;

typedef	struct		t_plan
{
	s_vecteur		v_plan;
}					s_plan;

void	new_image(t_env *e);
int		main(int argc, char **argv);
int		key_hook(int keycode, t_env *e);
