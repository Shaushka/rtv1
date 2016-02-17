/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:00:11 by agadiffe          #+#    #+#             */
/*   Updated: 2016/02/17 14:13:40 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"
#include <stdlib.h>

void			new_img_in_old_env(t_env *e, t_env *old)
{
	e->mlx_init.mlx = old->mlx_init.mlx;
	e->mlx_init.win = old->mlx_init.win;
	if (!(e->mlx_init.img.img_ptr = mlx_new_image(e->mlx_init.mlx,
											SCREEN_W, SCREEN_H)))
		ft_exit("Can't create image", 1);
	if (!(e->mlx_init.img.img_data = mlx_get_data_addr(e->mlx_init.img.img_ptr,
											&e->mlx_init.img.bpp,
											&e->mlx_init.img.sizeline,
											&e->mlx_init.img.endian)))
		ft_exit("Can't get image adress", 1);
	e->mlx_init.img.opp = e->mlx_init.img.bpp / 8;
}

void			init_and_draw(t_env *e, char *av)
{
	if (!(e->mlx_init.mlx = mlx_init()))
		ft_exit("Can't initialize minilibX", 1);
	if (!(e->mlx_init.win = mlx_new_window(e->mlx_init.mlx,
											SCREEN_W, SCREEN_H, av)))
		ft_exit("Can't create window", 1);
	if (!(e->mlx_init.img.img_ptr = mlx_new_image(e->mlx_init.mlx,
											SCREEN_W, SCREEN_H)))
		ft_exit("Can't create image", 1);
	if (!(e->mlx_init.img.img_data = mlx_get_data_addr(e->mlx_init.img.img_ptr,
											&e->mlx_init.img.bpp,
											&e->mlx_init.img.sizeline,
											&e->mlx_init.img.endian)))
		ft_exit("Can't get image adress", 1);
	e->mlx_init.img.opp = e->mlx_init.img.bpp / 8;
	init_keyring(e);
	ft_render(e);
	mlx_expose_hook(e->mlx_init.win, &expose_hook, e);
	mlx_hook(e->mlx_init.win, BUTTONRELEASE, BUTTONRELEASEMASK, &ft_click, e);
	mlx_hook(e->mlx_init.win, KEYPRESS, KEYPRESSMASK, &key_press_hook, e);
	mlx_loop(e->mlx_init.mlx);
}

void			init_obj(t_object *node)
{
	node->next = NULL;
	node->pos = set_vector(node->pos, 0, 0, 0);
	node->normal = set_vector(node->pos, 0, 0, 0);
	node->radius = 0;
	node->height = 0;
}

void			init_scene(t_env *e)
{
	e->scene = malloc(sizeof(t_scene));
	e->scene->l_obj = NULL;
	e->scene->light = NULL;
}
