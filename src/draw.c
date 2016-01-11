/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <chuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:12:09 by chuang            #+#    #+#             */
/*   Updated: 2016/01/11 19:07:09 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include '../includes/rtv1.h'

void			put_pxl_image(int x, int y, t_env *e, t_color color)
{
	int		ptr;

	ptr = y * e->sizeline + x * (e->bpp / 8);
	e->data[ptr] = color.b;
	e->data[ptr + 1] = color.g;
	e->data[ptr + 2] = color.r;
}
