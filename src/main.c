/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:49:52 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/13 17:31:26 by agadiffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_scene(t_env *e)
{
	(void)e;
	//parsing file scene here
}

int		main(int argc, char **argv)
{
	t_env e;

	argv = (char **)argv;
	if (argc != 1)
		ft_exit("usage: ./rtv1", 1);
	//get_scene(&e);
	init_and_draw(&e, argv[1]);
	return (0);
}
