/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:49:52 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/06 19:00:07 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_initialize(t_env *e)
{
	new_image(e);
}

static void		ft_wimg(t_env *e)
{
	generate(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	mlx_destroy_image(e->mlx, e->img);
}

int				main(int argc, char **argv)
{
	t_env e;

	argv = (char **)argv;
	if (argc != 1)
	{
		ft_putendl("Hey buddy, there was no need to give me any params, but 
				thanks anyway !"); 
	}

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, "RTV1");	
	ft_initialize(&e);

	return (0);
}
