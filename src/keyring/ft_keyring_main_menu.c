/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_main_menu.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:55 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		ft_get_mm_cmd_interface(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W && y >= 0 && y <= (double)INTER_H * (1. / 3.))
		return (e->key.mode = 3);
	if (x >= 0 && x <= INTER_W && y >= (double)INTER_H * (1. / 3.) &&
									y <= (double)INTER_H * (2. / 3.))
		return (e->key.mode = 4);
	if (x >= 0 && x <= INTER_W && y >= (double)INTER_H * (2. / 3.) &&
									y <= (double)INTER_H * (3. / 3.))
		return (e->key.mode = 7);
	return (e->key.mode);
}

void	spaw_main_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	set_color_from_rgb(&c, 90, 90, 90);
	ft_print_square(c,
		set_vector(v, 0., 0., 0.),
		set_vector(v, INTER_W, (double)INTER_H * (1. / 3.), 0), e);
	set_color_from_rgb(&c, 190, 190, 190);
	ft_print_square(c,
		set_vector(v, 0., (double)INTER_H * (1. / 3.), 0.),
		set_vector(v, INTER_W, (double)INTER_H * (2. / 3.), 0), e);
	set_color_from_rgb(&c, 255, 255, 255);
	ft_print_square(c,
		set_vector(v, 0., (double)INTER_H * (2. / 3.), 0.),
		set_vector(v, INTER_W, (double)INTER_H * (3. / 3.), 0), e);
	e->key.mode = 2;
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
							e->key.interface.img.img_ptr, 0, 0);
	ft_print_mm_ui(e);
}
