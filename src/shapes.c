/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/13 10:52:54 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_sphere(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir les dimensions de la sphere :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	ft_putstr("pikpikpik");
	read(0, tmp, 200);
	ft_putstr("pokpokpok");
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

void	ft_cylindre(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir les dimensions du cylindre :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	ft_putstr("pikpikpik");
	read(0, tmp, 200);
	ft_putstr("pokpokpok");
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
void	ft_cone(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir les dimensions du cone :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	ft_putstr("pikpikpik");
	read(0, tmp, 200);
	ft_putstr("pokpokpok");
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
void	ft_plan(t_env *e)
{
	char *tmp;

	ft_putstr("Nous allons maintenant definir la position du plan :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	ft_putstr("pikpikpik");
	read(0, tmp, 200);
	ft_putstr("pokpokpok");
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
