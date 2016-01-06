/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:12:09 by chuang            #+#    #+#             */
/*   Updated: 2015/12/09 11:54:42 by chuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include RTV1_H

#define WIN_W 640
#define WIN_H 480

#define HFOV 2 * atan(0.5 * WIN_H / 20)
#define WFOV 2 * atan(0.5 * WIN_W / 20)

void			put_pxl_image(int x, int y, t_env *e, t_color color)
{
	int		ptr;

	ptr = y * e->sizeline + x * (e->bpp / 8);
	e->data[ptr] = color.b;
	e->data[ptr + 1] = color.g;
	e->data[ptr + 2] = color.r;
}
