/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_light_interface.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:27:46 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 18:49:36 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

void	spawn_light_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	spawn_light_pos_controls(c, v, e);
	spawn_light_dir_controls(c, v, e);
	spawn_light_col_controls(c, v, e);
	spawn_light_int_controls(c, v, e);
	e->key.mode = 5;
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
							e->key.interface.img.img_ptr, 0, 0);
}

void	spawn_light_pos_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 100, 100);
	ft_print_square(c,
		set_vector(v, 0. , 0., 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 7.), 0), e);//light pos x +
	set_color_from_rgb(&c, 255, 20, 20);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (1. / 7.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 7.), 0), e);//light pos x -
	set_color_from_rgb(&c, 100, 155, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), 0., 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 7.), 0), e);//light pos y +
	set_color_from_rgb(&c, 20, 200, 20);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 7.), 0), e);//light pos y -
	set_color_from_rgb(&c, 100, 100, 200);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), 0., 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (1. / 7.), 0), e);//light pos z +
	set_color_from_rgb(&c, 10, 10, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (2. / 7.), 0), e);//light pos z -
}

void	spawn_light_dir_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 100, 100);
	ft_print_square(c,
		set_vector(v, 0. , (double)INTER_H * (2. / 7.), 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (3. / 7.), 0), e);//light dir x +
	set_color_from_rgb(&c, 255, 20, 20);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (3. / 7.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (4. / 7.), 0), e);//light dir x -
	set_color_from_rgb(&c, 100, 155, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (3. / 7.), 0), e);//light dir y +
	set_color_from_rgb(&c, 20, 200, 20);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (3. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (4. / 7.), 0), e);//light dir y -
	set_color_from_rgb(&c, 100, 100, 200);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (3. / 7.), 0), e);//light dir z +
	set_color_from_rgb(&c, 10, 10, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (3. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (4. / 7.), 0), e);//light dir z -
}

void	spawn_light_col_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 100, 100);
	ft_print_square(c,
		set_vector(v, 0. , (double)INTER_H * (4. / 7.), 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (5. / 7.), 0), e);//light color x +
	set_color_from_rgb(&c, 255, 20, 20);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (5. / 7.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (6. / 7.), 0), e);//light color x -
	set_color_from_rgb(&c, 100, 155, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (4. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (5. / 7.), 0), e);//light color y +
	set_color_from_rgb(&c, 20, 200, 20);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (5. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (6. / 7.), 0), e);//light color y -
	set_color_from_rgb(&c, 100, 100, 200);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (4. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (5. / 7.), 0), e);//light color z +
	set_color_from_rgb(&c, 10, 10, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (5. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (6. / 7.), 0), e);//light color z -
}

void	spawn_light_int_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 100, 100);
	ft_print_square(c,
		set_vector(v, 0. , (double)INTER_H * (6. / 7.), 0.),
		set_vector(v, INTER_W * (1. / 2.), (double)INTER_H, 0), e);//light intensity ++
	set_color_from_rgb(&c, 255, 20, 20);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 2.), (double)INTER_H * (6. / 7.), 0),
		set_vector(v, INTER_W, (double)INTER_H, 0), e);//light intensity --
}
