/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_cam_interface.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:43 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		ft_get_cm_cmd_interface_2(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > INTER_H * (2. / 4.) &&
		y <= INTER_H * (3. / 4.))
		return (e->key.mode = 600 + 7);
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > INTER_H * (3. / 4.) &&
		y <= INTER_H * (4. / 4.))
		return (e->key.mode = 600 + 8);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y > INTER_H * (2. / 4.) &&
		y <= INTER_H * (3. / 4.))
		return (e->key.mode = 600 + 9);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y > INTER_H * (2. / 4.) && y <= INTER_H * (4. / 4.))
		return (e->key.mode = 600 + 10);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > INTER_H * (2. / 4.) && y <= INTER_H * (3. / 4.))
		return (e->key.mode = 600 + 11);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > INTER_H * (3. / 4.) && y <= INTER_H * (4. / 4.))
		return (e->key.mode = 600 + 12);
	return (0);
}

int		ft_get_cm_cmd_interface(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > 0 && y <= INTER_H * (1. / 4.))
		return (e->key.mode = 600 + 1);
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > INTER_H * (1. / 4.) &&
		y <= INTER_H * (2. / 4.))
		return (e->key.mode = 600 + 2);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) && y > 0 &&
		y <= INTER_H * (1. / 4.))
		return (e->key.mode = 600 + 3);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y > INTER_H * (1. / 4.) && y <= INTER_H * (2. / 4.))
		return (e->key.mode = 600 + 4);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > 0 && y <= INTER_H * (1. / 4.))
		return (e->key.mode = 600 + 5);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > INTER_H * (1. / 4.) && y <= INTER_H * (2. / 4.))
		return (e->key.mode = 600 + 6);
	return (ft_get_cm_cmd_interface_2(x, y, e));
}

void	ft_mod_cam_inc(t_env *e, int mod)
{
	e->key.cam_inc.pos.x += mod == 601 ? 1 : 0;
	e->key.cam_inc.pos.x += mod == 602 ? -1 : 0;
	e->key.cam_inc.pos.y += mod == 603 ? 1 : 0;
	e->key.cam_inc.pos.y += mod == 604 ? -1 : 0;
	e->key.cam_inc.pos.z += mod == 605 ? 1 : 0;
	e->key.cam_inc.pos.z += mod == 606 ? -1 : 0;
	e->key.cam_inc.dir.x += mod == 607 ? 0.1 : 0;
	e->key.cam_inc.dir.x += mod == 608 ? -0.1 : 0;
	e->key.cam_inc.dir.y += mod == 609 ? 0.1 : 0;
	e->key.cam_inc.dir.y += mod == 610 ? -0.1 : 0;
	e->key.cam_inc.dir.z += mod == 611 ? 0.1 : 0;
	e->key.cam_inc.dir.z += mod == 612 ? -0.1 : 0;
}

void	spawn_cam_pos_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, 0., 0., 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 4.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (1. / 4.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 4.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), 0., 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 4.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 4.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 4.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), 0., 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (1. / 4.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 4.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (2. / 4.), 0), e);
}

void	spawn_cam_dir_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 95, 95, 95);
	ft_print_square(c,
		set_vector(v, 0., (double)INTER_H * (2. / 4.), 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (3. / 4.), 0), e);
	set_color_from_rgb(&c, 95, 95, 95);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (3. / 4.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (4. / 4.), 0), e);
	set_color_from_rgb(&c, 95, 95, 95);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 4.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (3. / 4.), 0), e);
	set_color_from_rgb(&c, 95, 95, 95);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (3. / 4.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (4. / 4.), 0), e);
	set_color_from_rgb(&c, 95, 95, 95);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 4.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (3. / 4.), 0), e);
	set_color_from_rgb(&c, 95, 95, 95);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (3. / 4.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (4. / 4.), 0), e);
}
