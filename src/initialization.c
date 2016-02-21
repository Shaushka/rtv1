/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:59 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

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
	e->cam.pos = (t_vector){0., 0., 0.};
	e->cam.dir = unit_vector((t_vector){1., 0., 0.});
	e->ambiant = e->lights ? e->lights->ambiant : AMBIANT;
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
	node->cut = set_vector(node->cut, 0, 0, 0);
	node->normal = set_vector(node->normal, 0, 0, 0);
	node->dir = set_vector(node->dir, 0, 0, 0);
	node->color = (t_color){0, 0, 0};
	node->radius = 0;
	node->height = 0;
	node->shine = 0.0;
	node->checkered = 0;
	node->reflect = 0.0;
	node->refraction = 0.0;
	node->bundle = -1;
}

void			init_light(t_light *node)
{
	node->type = NORMAL;
	node->pos = set_vector(node->pos, 0, 0, 0);
	node->dir = set_vector(node->dir, 0, 0, 0);
	node->color = (t_color){0, 0, 0};
	node->intensity = 0;
	node->ambiant = AMBIANT;
	node->next = NULL;
	node->bundle = -1;
}

void			init_scene(t_env *e)
{
	e->scene = malloc(sizeof(t_scene));
	e->scene->l_obj = NULL;
	e->scene->light = NULL;
}
