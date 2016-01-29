/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadiffe <agadiffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 17:00:11 by agadiffe          #+#    #+#             */
/*   Updated: 2016/01/29 14:19:29 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"
#include <stdlib.h>

void			ft_exit(char *str, int n)
{
	ft_putendl_fd(str, 2);
	exit(n);
}

void			quit_and_free(t_env *e)
{
	mlx_destroy_image(e->mlx_init.mlx, e->mlx_init.img.img_ptr);
	mlx_destroy_window(e->mlx_init.mlx, e->mlx_init.win);
	exit(0);
}

void			init_env(t_env *e)
{
	(void)e;
	//if need, if not, jsut delete this function
}

void			init_and_draw(t_env *e, char *av)
{
	init_env(e);
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
	ft_render(e);
	mlx_expose_hook(e->mlx_init.win, &expose_hook, e);
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
	node->constant = 0;
}

void			init_scene(t_env *e)
{
	e->scene->l_obj->next = NULL;
	e->scene->light->next = NULL;
}
