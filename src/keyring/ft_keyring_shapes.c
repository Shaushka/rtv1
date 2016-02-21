/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_shapes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:06 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

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

void		ft_print_square(t_color c, t_vector st, t_vector en, t_env *e)
{
	int			x;
	int			y;
	int			addr;

	y = st.y;
	while (y < en.y)
	{
		x = st.x;
		while (x < en.x)
		{
			addr = y * e->key.interface.img.sizeline + x *
					e->key.interface.img.opp;
			e->key.interface.img.img_data[addr + 0] = c.b;
			e->key.interface.img.img_data[addr + 1] = c.g;
			e->key.interface.img.img_data[addr + 2] = c.r;
			x++;
		}
		y++;
	}
}
