/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:59:22 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 19:20:25 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		diameter(t_sphere *node)
{
	char *tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	read(0, tmp, 200);
	while (!ft_isnum(tmp))
	{
		ft_putstr("Diametre (entre 1 et 10) : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!ft_isnum(tmp) || ft_atoi(tmp) > 10 || ft_atoi(tmp) < 1)
			ft_putstr("Entrez un nombre entre 1 et 10 !");
	}
	node->radius = ft_atoi(tmp);
	free(tmp);
}

int		count_objects(t_env *e)
{
	int i;
	t_object *a; 

	i = 0;
	a = e->scene->l_obj;	
	while (a->next != NULL)
	{
		i++;
		a = a->next;
	}
	free (a);
	return (i);
}

int		constant(t_object *node)
{
	char *tmp;

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
	node->constant = ft_atoi(tmp);
	free(tmp);

}
