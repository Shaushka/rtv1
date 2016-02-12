/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:49:52 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/12 17:31:05 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdlib.h>

void	get_scene(t_env *e)
{
	(void)e;
	//parsing file scene here
}

int		main(int argc, char **argv)
{
	t_env	e;

	init_scene(&e);
	//if(INTERACTIVE)
	//		create_scene(&e);
	//else
	init_lights(&e);
	set_list_obj(&e);
	argv = (char **)argv;
	if (argc != 1)
		ft_exit("usage: ./rtv1", 1);
	//get_scene(&e);
	init_and_draw(&e, argv[0]);
	return (0);
}
