/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_object_interface.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 21:58:32 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 22:34:33 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

int		ft_get_om_cmd_interface(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > 0 && y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 1);
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > INTER_H * (1. / 2.) &&
		y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 2);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) && y > 0 &&
		y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 3);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y > INTER_H * (1. / 2.) && y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 4);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > 0 && y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 5);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > INTER_H * (1. / 2.) && y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 6);
	return (e->key.mode);
}

void	spawn_obj_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	spawn_obj_pos_controls(c, v, e);
	e->key.mode = 8;
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
							e->key.interface.img.img_ptr, 0, 0);
}

void	spawn_obj_pos_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 255, 100, 100);
	ft_print_square(c,
		set_vector(v, 0. , 0., 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 2.), 0), e);//cam pos x +
	set_color_from_rgb(&c, 255, 20, 20);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (1. / 2.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 2.), 0), e);//cam pos x -
	set_color_from_rgb(&c, 100, 155, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), 0., 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 2.), 0), e);//cam pos y +
	set_color_from_rgb(&c, 20, 200, 20);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 2.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 2.), 0), e);//cam pos y -
	set_color_from_rgb(&c, 100, 100, 200);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), 0., 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (1. / 2.), 0), e);//cam pos z +
	set_color_from_rgb(&c, 10, 10, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 2.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (2. / 2.), 0), e);//cam pos z -
}

void	ft_print_pending_objpos_modif(t_object *l, t_env *e)
{
	char	*li;
	char	*tmp1;
	char	*tmp2;
	char	*swp;

	tmp1 = ft_itoa((int)(l->pos.x));
	tmp2 = ft_itoa((int)(l->pos.y));
	li = ft_strjoin("Pending Object position status : x = ", tmp1);
	swp = ft_strjoin(li, " y = ");
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&swp);
	swp = ft_strjoin(li, " z = ");
	tmp1 = ft_itoa((int)(l->pos.z));
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&swp);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, INTER_W + 10,
					INTER_H * (1. / 2.), 0x0, li);
	ft_strdel(&li);
}

void	ft_print_selected_obj(t_env *e)
{
	char	*tmp1;
	char	*li;

	tmp1 = ft_itoa((int)(e->key.selected_obj));
	li = ft_strjoin("Selected Object : ", tmp1);
	ft_strdel(&tmp1);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, INTER_W + 10,
					INTER_H + 10, 0x0, li);
	ft_strdel(&li);
}

void	ft_mod_obj_inc(t_env *e, int mod)
{
	t_object	*swp;

	swp = ft_get_obj_at_nb(e->key.selected_obj, e->scene->l_obj);
	swp->pos.x += mod == 801 ? 1 : 0;
	swp->pos.x -= mod == 802 ? 1 : 0;
	swp->pos.y += mod == 803 ? 1 : 0;
	swp->pos.y -= mod == 804 ? 1 : 0;
	swp->pos.z += mod == 805 ? 1 : 0;
	swp->pos.z -= mod == 806 ? 1 : 0;
}
