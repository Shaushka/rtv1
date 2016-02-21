/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_parser_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:36 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void		assign_normal_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	if (obj)
	{
		while (str[i] != '/')
			i++;
		(*obj)->normal.x = ft_atof(str);
		while (str[i] != '/')
			i++;
		(*obj)->normal.y = ft_atof(&str[i + 1]);
		i++;
		while (str[i] != '/')
			i++;
		(*obj)->normal.z = ft_atof(&str[i + 1]);
		(*obj)->normal = unit_vector((*obj)->normal);
	}
}

void		assign_dir_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	if (obj)
	{
		while (str[i] != '/')
			i++;
		(*obj)->dir.x = ft_atof(str);
		while (str[i] != '/')
			i++;
		(*obj)->dir.y = ft_atof(&str[i + 1]);
		i++;
		while (str[i] != '/')
			i++;
		(*obj)->dir.z = ft_atof(&str[i + 1]);
		(*obj)->dir = unit_vector((*obj)->dir);
	}
}

void		assign_pos_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	if (obj)
	{
		while (str[i] != '/')
			i++;
		(*obj)->pos.x = ft_atof(str);
		while (str[i] != '/')
			i++;
		(*obj)->pos.y = ft_atof(&str[i + 1]);
		i++;
		while (str[i] != '/')
			i++;
		(*obj)->pos.z = ft_atof(&str[i + 1]);
	}
}
