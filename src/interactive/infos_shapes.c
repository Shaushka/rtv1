/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:26 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void			radius(t_object *node)
{
	char		*tmp;
	char		*clean;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Indiquez le rayon : ");
	read(0, tmp, 200);
	printf("Putain de valeur de mon radius avant clean : \"%s\"\n", tmp);
	clean = no_more_spaces(tmp);
	printf("Putain de valeur de mon radius APRES clean : \"%s\"\n", clean);
	while (!ft_isnum(clean))
	{
		ft_putstr("Rayon (entre 1 et 10) : ");
		ft_bzero(clean, 200);
		read(0, clean, 200);
		if (!ft_isnum(clean) || ft_atoi(clean) > 10 || ft_atoi(clean) < 1)
			ft_putstr("Entrez un nombre entre 1 et 10 !");
	}
	node->radius = ft_atoi(clean);
	free(clean);
}

void			height(t_object *node)
{
	char		*tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	read(0, tmp, 200);
	while (!ft_isnum(tmp))
	{
		ft_putstr("Hauteur (entre 1 et 10) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 10 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 10 !");
	}
	node->height = ft_atoi(tmp) / 2;
	free(tmp);
}

void			shine(t_object *node)
{
	char		*tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	read(0, tmp, 200);
	while (!ft_isnum(tmp))
	{
		ft_putstr("Constante du plan (entre 1 et 10) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 10 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 10 !");
	}
	node->shine = ft_atoi(tmp);
	free(tmp);
}
