/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_reset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:04 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	set_cam_to_zero(t_cam *cam)
{
	t_vector	v;

	cam->pos = set_vector(v, 0, 0, 0);
	cam->dir = set_vector(v, 0, 0, 0);
	cam->h = set_vector(v, 0, 0, 0);
	cam->d = set_vector(v, 0, 0, 0);
}

void	init_keyring(t_env *e)
{
	e->key.mouse_x = 0;
	e->key.mouse_y = 0;
	e->key.interface.mlx = e->mlx_init.mlx;
	e->key.interface.win = e->mlx_init.win;
	e->key.selected_light = 0;
	e->key.selected_obj = 0;
	e->key.mode = -1;
	set_cam_to_zero(&(e->key.cam_inc));
	new_interface_image(e);
}

void	new_interface_image(t_env *e)
{
	if (!(e->key.interface.img.img_ptr = mlx_new_image(
													e->key.interface.mlx,
													SCREEN_W / 5,
													SCREEN_H / 5)))
		ft_exit("Can't create image", 1);
	if (!(e->key.interface.img.img_data = mlx_get_data_addr(
												e->key.interface.img.img_ptr,
												&e->key.interface.img.bpp,
												&e->key.interface.img.sizeline,
												&e->key.interface.img.endian)))
		ft_exit("Can't get image adress", 1);
	e->key.interface.img.opp = e->key.interface.img.bpp / 8;
}

void	hide_interface_image(t_env *e)
{
	mlx_put_image_to_window(e->mlx_init.mlx,
							e->mlx_init.win,
							e->mlx_init.img.img_ptr,
							0,
							0);
	e->key.mode = -1;
}
