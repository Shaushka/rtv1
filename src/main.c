/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:49:52 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/30 12:31:12 by chuang           ###   ########.fr       */
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
	
//	create_scene(&e);
	e.lights = malloc(sizeof(t_light));
	e.lights->next = NULL;
	init_lights(e);
	argv = (char **)argv;
	if (argc != 1)
		ft_exit("usage: ./rtv1", 1);
	//get_scene(&e);
	init_and_draw(&e, argv[0]);
	return (0);
}
