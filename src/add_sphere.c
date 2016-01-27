/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/27 12:21:33 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

void	sphere_dimensions(t_env *e, t_sphere *node)
{
	char *tmp;

	ft_putstr("Definition des dimensions de la sphere :\n");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while (!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 100) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 100 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 100 !");
	}//faire en sorte que le nombre soit assigne aux cases correspondantes
	node->radius = ft_atoi(tmp);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la position de la sphere :");
	while (!ft_isnum(tmp))
	{
		ft_putstr("X (superieur a zero) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) < 0)
			ft_putstr("Entrez un nombre superieur a zero !");
	}//gerer si trop loin pour etre visible ??
	node->pos.x = ft_atoi(tmp);
	free(tmp);
}

void	add_sphere(t_env *e)
{
	t_sphere *a;
	t_sphere *b;

	a = (t_sphere*)malloc(sizeof(t_sphere));
	if (!e->scene->spheres)//je regarde si un maillon existe deja
	{
		e->scene->spheres = a;//si non, je cree le premier maillon
//TODO	if (e->scene->spheres == NULL)
		//mettre protection du malloc avec exit et erreur
		e->scene->spheres->radius = 0;
		e->scene->spheres->next = NULL;
		e->scene->spheres->pos = set_vector(e->scene->spheres->pos, 0, 0, 0);
	}
	else
	{
	//si oui, j'ajoute un maillon apres la chaine existante :
	//je vais au bout de la liste chainee
		b = e->scene->spheres;
		while (b->next != NULL)
			b = b->next;
		//je prends le maillon a deja cree et je l'ajoute au bout de la liste
		b->next = a;
		a->radius = 0;
		a->next = NULL;
		a->pos = set_vector(a->pos, 0, 0, 0);
	}
	sphere_dimensions(e, a);
}