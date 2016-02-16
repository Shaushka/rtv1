/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_bar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:12:09 by mgras             #+#    #+#             */
/*   Updated: 2016/02/16 16:41:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include <stdio.h>

void		ft_print_line(t_env *ev, t_color c, t_vector s, t_vector e)
{
	t_vector	p;
	int			ix;
	int			iy;
	int			addr;

	p.x = e.x - s.x;
	p.y = e.y - s.y;
	p.z = p.x >= p.y ? p.x : p.y;
	p.z *= p.z > 0 ? 1 : -1;
	if (p.z == 0)
		return ;
	ix = p.x / p.z;
	iy = p.y / p.z;
	while (p.z-- > 0)
	{
		addr = s.y * ev->mlx_init.img.sizeline + s.x * ev->mlx_init.img.opp;
		put_pixel_to_img(ev, addr, c);
		s.x += ix;
		s.y += iy;
	}
}

void		ft_gen_loading_border(t_env *e)
{
	t_vector	st;
	t_vector	en;
	t_vector	v;
	t_color		c;

	set_color_from_rgb(&c, 255, 255, 255);
	st.x = (int)(0. + ((double)SCREEN_W / 100. * 5.));
	st.y = (int)((double)SCREEN_H - ((double)SCREEN_H / 100. * 5.));
	en.y = (int)((double)SCREEN_H - ((double)SCREEN_H / 100. * 2.));
	en.x = (int)((double)SCREEN_W - (((double)SCREEN_W / 100. * 5.)));
	ft_print_line(e, c, set_vector(v, st.x, st.y, 0),\
					set_vector(v, en.x, st.y, 0));
	ft_print_line(e, c, set_vector(v, st.x, en.y, 0),\
					set_vector(v, en.x, en.y, 0));
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,\
					e->mlx_init.img.img_ptr, 0, 0);
}

void		ft_fill_loading_border(t_env *e, int x)
{
	t_vector	en;
	t_vector	st;
	t_vector	v;
	t_color		c;

	set_color_from_rgb(&c, x + x, x + x, x);
	en.x = x;
	en.y = (int)((double)SCREEN_H - ((double)SCREEN_H / 100. * 4.));
	st.y = (int)((double)SCREEN_H - ((double)SCREEN_H / 100. * 3.));
	st.x = x;
	if (st.x < 0)
		return ;
	ft_print_line(e, c, set_vector(v, st.x, en.y, 0),\
				set_vector(v, st.x, st.y, 0));
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,\
				e->mlx_init.img.img_ptr, 0, 0);
}

int			ft_loading_bar(int x, t_env *e)
{
	if (e == NULL)
		return (1);
	if (x == 1)
		ft_gen_loading_border(e);
	ft_fill_loading_border(e, x);
	if (x + 1 == SCREEN_W)
		mlx_destroy_image(e->mlx_init.mlx, e->mlx_init.img.img_ptr);
	return (0);
}
