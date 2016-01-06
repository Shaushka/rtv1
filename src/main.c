/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:49:52 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/06 18:32:35 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
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
