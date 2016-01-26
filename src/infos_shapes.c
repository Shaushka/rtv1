/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:59:22 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/26 16:57:44 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_spheres(t_env *e)
{
	int i;
	t_sphere *a; 

	i = 0;
	a = e->scene->spheres;	
	while (a->next != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		count_cylinders(t_env *e)
{
	int i;
	t_cylinder *a; 

	i = 0;
	a = e->scene->cylinders;	
	while (a->next != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		count_cones(t_env *e)
{
	int i;
	t_cone *a; 

	i = 0;
	a = e->scene->cones;	
	while (a->next != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int		count_planes(t_env *e)
{
	int i;
	t_plane *a; 

	i = 0;
	a = e->scene->planes;	
	while (a->next != NULL)
	{
		i++;
		a = a->next;
	}
	return (i);
}

