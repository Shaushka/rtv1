/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:48 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			put_pixel_to_img(t_env *e, int addr, t_color color)
{
	e->mlx_init.img.img_data[addr + 0] = color.b;
	e->mlx_init.img.img_data[addr + 1] = color.g;
	e->mlx_init.img.img_data[addr + 2] = color.r;
}

void			blend_color(t_color *c, t_color c1, t_color c2, double percent)
{
	c->r = c1.r + percent * (c2.r - c1.r);
	c->g = c1.g + percent * (c2.g - c1.g);
	c->b = c1.b + percent * (c2.b - c1.b);
}

void			set_color_from_rgb(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void			set_color_from_img(t_color *color, char *data, int addr)
{
	color->b = data[addr + 0];
	color->g = data[addr + 1];
	color->r = data[addr + 2];
}

void			get_true_color_value(t_color *color)
{
	if (color->b < 0)
		color->b = 256 + color->b;
	if (color->g < 0)
		color->g = 256 + color->g;
	if (color->r < 0)
		color->r = 256 + color->r;
}
