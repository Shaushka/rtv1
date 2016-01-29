/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/27 15:07:33 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

t_object		*create_sphere(t_env *e)
{
	t_object *a;
	t_object *b;

	a = (t_object*)malloc(sizeof(t_object));
	init_obj(a);//MET TOUTES LES VALEURS A ZERO
	if (e->scene->l_obj = NULL)//si le l_obj est vide
	{
		e->scene->l_obj = a;//j'accroche le t_object A a liste_obj
		if (e->scene->l_obj == NULL)
			return (NULL);
	}
	else//si il y a deja d'autres objets
	{
		b = e->scene->l_obj;
		while (b->next != NULL)
			b = b->next;//je vais prendre le dernier maillon
		b->next = a;//et j'accroche le t_object A a la liste
	}
	return (a);
}

void			input_sphere(t_env *e)
{
	t_object	*node;
	node = create_sphere(e);
	diameter(node);
	position(node);
}
