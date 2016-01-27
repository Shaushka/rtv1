/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agadiffe <agadiffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:59:19 by agadiffe          #+#    #+#             */
/*   Updated: 2016/01/27 11:22:53 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"
#include <stdlib.h>
#include <stdio.h>

int				expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
	return (0);
}

int		key_press_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit (0);

	if (keycode == KEY_UP)
	{
		e->lights->pos.x += 1;	
		printf("PageUp\n");
		ft_render(e);
	}

	if (keycode == KEY_DOWN)
	{
		e->lights->pos.x -= 1;	
		printf("PageDown\n");
		ft_render(e);
	}
	return (0);
}
