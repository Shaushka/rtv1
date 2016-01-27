/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/27 15:10:49 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

static void		sphere_position_z(t_sphere *node)
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
	sphere_position_z(node);
}

static void		sphere_position_y(t_sphere *node)
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
	sphere_position_z(node);
}

static void		sphere_position_x(t_sphere *node)
{
	char *tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la position de la sphere :");
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
	sphere_position_y(node);
}

static void		sphere_diameter(t_sphere *node)
{
	char *tmp;

	ft_putstr("Definition des dimensions de la sphere :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	read(0, tmp, 200);
	while (!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 100) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 100 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 100 !");
	}
	node->radius = ft_atoi(tmp);
	free(tmp);
	sphere_position_x(node);
}

void			add_plane(t_env *e)
{
	t_plane *a;
	t_sphere *b;

	a = (t_sphere*)malloc(sizeof(t_sphere));
	if (!e->scene->spheres)
	{
		e->scene->spheres = a;
//TODO	if (e->scene->spheres == NULL)
		//mettre protection du malloc avec exit et erreur
		e->scene->spheres->radius = 0;
		e->scene->spheres->next = NULL;
		e->scene->spheres->pos = set_vector(e->scene->spheres->pos, 0, 0, 0);
	}
	else
	{
		b = e->scene->spheres;
		while (b->next != NULL)
			b = b->next;
		b->next = a;
		a->radius = 0;
		a->next = NULL;
		a->pos = set_vector(a->pos, 0, 0, 0);
	}
	sphere_diameter(a);
}
