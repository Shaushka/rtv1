/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/26 19:32:50 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"
//GERER SI Y'A PAS DE T_SPHERE DEJA EXISTANT
void	add_sphere(t_env *e)
{
	char *tmp;
	t_sphere *a;
	t_sphere *b;

	a = (t_sphere*)malloc(sizeof(t_sphere));	
	//je regarde si un maillon existe deja
	if (!e->scene->spheres)
	{
		//si non, je cree le premier maillon
		e->scene->spheres = a;
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

void	sphere_dimensions(t_env *e, t_sphere *node)
{
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
		//faire en sorte que le nombre soit assigne aux cases correspondantes

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
