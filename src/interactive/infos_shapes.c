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
//possibilite de faire une fonction qui compte les objets par type
