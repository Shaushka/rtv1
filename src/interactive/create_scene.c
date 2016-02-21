/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:23 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static int		silent_isshape(char *str)
{
	if (ft_strequ(str, "sphere\n") || ft_strequ(str, "Sphere\n"))
		return (1);
	if (ft_strequ(str, "cylinder\n") || ft_strequ(str, "Cylinder\n"))
		return (2);
	if (ft_strequ(str, "cone\n") || ft_strequ(str, "Cone\n"))
		return (3);
	if (ft_strequ(str, "plan\n") || ft_strequ(str, "Plan\n"))
		return (4);
	else
		return (0);
}

static int		isshape(char *str)
{
	if (ft_strequ(str, "sphere\n") || ft_strequ(str, "Sphere\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (1);
	}
	if (ft_strequ(str, "cylinder\n") || ft_strequ(str, "Cylinder\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (2);
	}
	if (ft_strequ(str, "cone\n") || ft_strequ(str, "Cone\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (3);
	}
	if (ft_strequ(str, "plan\n") || ft_strequ(str, "Plan\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (4);
	}
	else
		return (0);
}

void			create_scene(t_env *e)
{
	int			x;
	char		*tmp;

	ft_putstr("Quel type d'element voulez-vous ajouter a la scene ? : ");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while (!isshape(tmp))
	{
		ft_putstr("Choisissez sphere, cone, cylindre ou plan : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
	}
	x = silent_isshape(tmp);
	if (x == 1)
		input_sphere(e);
	else if (x == 2)
		input_cylinder(e);
	else if (x == 3)
		input_cone(e);
	else if (x == 4)
		input_plane(e);
	free(tmp);
}
