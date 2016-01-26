/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:10:14 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/26 17:38:45 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

static int		isshape(char *str)
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

void		ft_initialize(t_env *e)
{
	e->scene->spheres = NULL;	
	e->scene->cylinders = NULL;	
	e->scene->planes = NULL;	
	e->scene->cones = NULL;	
}
void	create_scene(t_env *e)
{//PENSER A INITIALISER LES VALEURS DES T_SPHERE, PLAN, ETC. A 0 pour le cas ou ils ne sont pas utlises
	ft_putstr("Quel type d'element voulez-vous ajouter a la scene ? : ");
	char *tmp;

	tmp	= ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while (!isshape(tmp))
	{	
		ft_putstr("Choisissez sphere, cone, cylindre ou plan : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!isshape(tmp))
			ft_putstr("Vous m'avez encore demande l'impossible ! ");
	}
	if (isshape(tmp))
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
	if (isshape(tmp) == 1)//SPHERE
		add_sphere(e);
	else if (isshape(tmp) == 2)
		add_cylinder(e);
	else if (isshape(tmp) == 3)
		add_cone(e);
	else if (isshape(tmp) == 4)
		add_plane(e);
	free(tmp);
}

int		main(int argc, char **argv)
{
	t_env e;
	ft_initialize(&e);
	argv = (char **)argv; 
	if (argc > 1)
		return (0);
	else
	{
		create_scene(&e);
		return (1);
	}
}
