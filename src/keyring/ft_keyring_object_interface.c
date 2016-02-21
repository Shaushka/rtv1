/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_object_interface.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:02 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	spawn_obj_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	hide_interface_image(e);
	spawn_obj_pos_controls(c, v, e);
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
							e->key.interface.img.img_ptr, 0, 0);
	ft_print_obj_ui(e);
	ft_print_selected_obj(e);
	ft_print_pending_objpos_modif(ft_get_obj_at_nb(e->key.selected_obj,
									e->scene->l_obj), e);
	e->key.mode = 8;
}

void	spawn_obj_pos_controls(t_color c, t_vector v, t_env *e)
{
	set_color_from_rgb(&c, 200, 200, 200);
	ft_print_square(c,
		set_vector(v, 0., 0., 0.),
		set_vector(v, (1. / 3.) * INTER_W, (1. / 2.) * (double)INTER_H, 0), e);
	set_color_from_rgb(&c, 100, 100, 100);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (1. / 2.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 2.), 0), e);
	set_color_from_rgb(&c, 200, 200, 200);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), 0., 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 2.), 0), e);
	set_color_from_rgb(&c, 100, 100, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 2.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 2.), 0), e);
	set_color_from_rgb(&c, 200, 200, 200);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), 0., 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (1. / 2.), 0), e);
	set_color_from_rgb(&c, 100, 100, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 2.), 0.),
		set_vector(v, INTER_W * (3. / 3.), (double)INTER_H * (2. / 2.), 0), e);
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
	if (!swp)
		return ;
	if (swp && swp->bundle != -1)
	{
		ft_mod_grouped_obj(e, mod, swp->bundle);
		return ;
	}
	swp->pos.x += mod == 801 ? 1 : 0;
	swp->pos.x -= mod == 802 ? 1 : 0;
	swp->pos.y += mod == 803 ? 1 : 0;
	swp->pos.y -= mod == 804 ? 1 : 0;
	swp->pos.z += mod == 805 ? 1 : 0;
	swp->pos.z -= mod == 806 ? 1 : 0;
}
