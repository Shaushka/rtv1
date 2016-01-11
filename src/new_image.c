/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:51:18 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/06 18:51:32 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


void			new_image(t_env *e)
{
	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
}
