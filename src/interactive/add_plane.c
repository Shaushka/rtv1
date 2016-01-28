/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 12:28:27 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

static void		plane_position_z(t_plane *node)
{
	char *tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("y (entre -7.5 et 7.5) : ");
	read(0, tmp, 200);
	while (!ft_isnum(tmp) || ft_atoi(tmp) < -7.5 || ft_atoi(tmp) > 7.5)
	{
		ft_bzero(tmp, 200);
		ft_putstr("Entrez un nombre entre -7,5 et 7,5  !");
		read(0, tmp, 200);
	}
	//gerer si certains points ne sont pas dans l'image mais visible qd mm
	node->pos.y = ft_atoi(tmp);
	free(tmp);
	plane_position_z(node);
}

static void		plane_position_y(t_plane *node)
{
	char *tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("y (entre -7.5 et 7.5) : ");
	read(0, tmp, 200);
	while (!ft_isnum(tmp) || ft_atoi(tmp) < -7.5 || ft_atoi(tmp) > 7.5)
	{
		ft_bzero(tmp, 200);
		ft_putstr("Entrez un nombre entre -7,5 et 7,5  !");
		read(0, tmp, 200);
	}
	//gerer si trop sur le cote pour que le centre soit visible
	//mais il peut deborder dans l'image
	node->pos.y = ft_atoi(tmp);
	free(tmp);
	plane_position_z(node);
}

static void		plane_position_x(t_plane *node)
{
	char *tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la position de la plane :");
	ft_putstr("x (superieur a zero) : ");
	read(0, tmp, 200);
	while (!ft_isnum(tmp) || ft_atoi(tmp) < 0)
	{
		ft_bzero(tmp, 200);
		ft_putstr("Entrez un nombre superieur a zero !");
		read(0, tmp, 200);
	}//gerer si trop loin pour etre visible ??
	node->pos.x = ft_atoi(tmp);
	free(tmp);
	plane_position_y(node);
}

static void		plane_pos(t_plane *node)
{
	char *tmp;

	ft_putstr("Definition du plan :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	read(0, tmp, 200);
	while (!ft_isnum(tmp))
	{
		ft_putstr("Point d'origine (sous la forme x/y/z) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isvect(tmp))
			ft_putstr("Entrez des valeurs numeriques sous la forme x/y/z !");
	}
	node->radius = ft_atoi(tmp);
	free(tmp);
	plane_position_x(node);
}

void			add_plane(t_env *e)
{
	t_plane *a;
	t_plane *b;

	a = (t_plane*)malloc(sizeof(t_plane));
	if (!e->scene->planes)
	{
//TODO	if (e->scene->planes == NULL)
		//mettre protection du malloc avec exit et erreur
		a->pos = set_vector(a->pos, 0, 0, 0);
		a = set_vector(a->normal, 0, 0, 0);
		a->constant = 0;
		a->next = NULL;
		e->scene->planes = a;
	}
	else
	{
		b = e->scene->planes;
		while (b->next != NULL)
			b = b->next;
		b->next = a;
		a->pos = set_vector(a->pos, 0, 0, 0);
		a = set_vector(a->normal, 0, 0, 0);
		a->constant = 0;
		a->next = NULL;
	}
	free(b);
	plane_pos(a);
}
