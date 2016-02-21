/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_light_interface.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:53 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	spawn_light_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	ft_print_pending_lightpos_modif(
			ft_get_light_at_nb(e->key.selected_light, e->scene->light), e);
	ft_print_pending_lightdir_modif(
			ft_get_light_at_nb(e->key.selected_light, e->scene->light), e);
	ft_print_pending_lightcol_modif(
			ft_get_light_at_nb(e->key.selected_light, e->scene->light), e);
	ft_print_pending_lightint_modif(
			ft_get_light_at_nb(e->key.selected_light, e->scene->light), e);
	ft_print_selected_light(e);
	spawn_light_pos_controls(c, v, e);
	spawn_light_dir_controls(c, v, e);
	spawn_light_col_controls(c, v, e);
	spawn_light_int_controls(c, v, e);
	e->key.mode = 5;
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->key.interface.img.img_ptr, 0, 0);
	ft_print_light_ui(e);
}

void	spawn_light_pos_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, 0., 0., 0.),
		set_vector(v, (1. / 3.) * INTER_W,
		(1. / 7.) * (double)INTER_H, 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, 0, (double)INTER_H * (1. / 7.), 0),
		set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (2. / 7.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 3.), 0., 0.),
		set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (1. / 7.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (1. / 7.), 0.), set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (2. / 7.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, INTER_W * (2. / 3.), 0., 0.),
		set_vector(v, INTER_W * (3. / 3.),
		(double)INTER_H * (1. / 7.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (1. / 7.), 0.), set_vector(v, INTER_W * (3. / 3.),
		(double)INTER_H * (2. / 7.), 0), e);
}

void	spawn_light_dir_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 155, 155, 155);
	ft_print_square(c, set_vector(v, 0., (double)INTER_H * (2. / 7.), 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (3. / 7.), 0), e);
	set_color_from_rgb(&c, 155, 155, 155);
	ft_print_square(c, set_vector(v, 0, (double)INTER_H * (3. / 7.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (4. / 7.), 0), e);
	set_color_from_rgb(&c, 155, 155, 155);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (2. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (3. / 7.), 0), e);
	set_color_from_rgb(&c, 155, 155, 155);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (3. / 7.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (4. / 7.), 0), e);
	set_color_from_rgb(&c, 155, 155, 155);
	ft_print_square(c, set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (2. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (3. / 7.), 0), e);
	set_color_from_rgb(&c, 155, 155, 155);
	ft_print_square(c, set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (3. / 7.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (4. / 7.), 0), e);
}

void	spawn_light_col_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 55, 55, 55);
	ft_print_square(c, set_vector(v, 0., (double)INTER_H * (4. / 7.), 0.),
		set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (5. / 7.), 0), e);
	set_color_from_rgb(&c, 55, 55, 55);
	ft_print_square(c, set_vector(v, 0, (double)INTER_H * (5. / 7.), 0),
		set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (6. / 7.), 0), e);
	set_color_from_rgb(&c, 55, 55, 55);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (4. / 7.), 0.), set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (5. / 7.), 0), e);
	set_color_from_rgb(&c, 55, 55, 55);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 3.),
		(double)INTER_H * (5. / 7.), 0.), set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (6. / 7.), 0), e);
	set_color_from_rgb(&c, 55, 55, 55);
	ft_print_square(c, set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (4. / 7.), 0.), set_vector(v, INTER_W * (3. / 3.),
		(double)INTER_H * (5. / 7.), 0), e);
	set_color_from_rgb(&c, 55, 55, 55);
	ft_print_square(c, set_vector(v, INTER_W * (2. / 3.),
		(double)INTER_H * (5. / 7.), 0.), set_vector(v, INTER_W * (3. / 3.),
		(double)INTER_H * (6. / 7.), 0), e);
}

void	spawn_light_int_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c, set_vector(v, 0., (double)INTER_H * (6. / 7.), 0.),
		set_vector(v, INTER_W * (1. / 2.), (double)INTER_H, 0), e);
	set_color_from_rgb(&c, 100, 100, 100);
	ft_print_square(c, set_vector(v, INTER_W * (1. / 2.),
		(double)INTER_H * (6. / 7.), 0),
		set_vector(v, INTER_W, (double)INTER_H, 0), e);
}
