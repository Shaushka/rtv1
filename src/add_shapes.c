/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shapes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/26 15:55:47 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

void	add_sphere(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir les dimensions de la sphere :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while(!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 100) : ");
	   	ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 100 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 100 !");		
	}
	free(tmp);	
}

void	add_cylinder(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir les dimensions du cylindre :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while(!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 100) : ");
	   	ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 100 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 100 !");		
	}	
	free(tmp);	
}
void	add_cone(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir les dimensions du cone :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while(!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 100) : ");
	   	ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 100 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 100 !");		
	}	
	free(tmp);	
}
void	add_plane(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir la position du plan :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while(!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 100) : ");
	   	ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 100 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 100 !");		
	}	
	free(tmp);	
}
