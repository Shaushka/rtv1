/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:36:45 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/17 13:26:28 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"
#include <stdlib.h>

void			ft_exit(char *str, int n)
{
	ft_putendl_fd(str, 2);
	exit(n);
}

void			quit_and_free(t_env *e)
{
	mlx_destroy_image(e->key.interface.mlx, e->key.interface.img.img_ptr);
	mlx_destroy_image(e->mlx_init.mlx, e->mlx_init.img.img_ptr);
	mlx_destroy_window(e->mlx_init.mlx, e->mlx_init.win);
	exit(0);
}
