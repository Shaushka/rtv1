/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kervrangwendoline <kervrangwendoline@student.42.fr>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 14:26:41 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/19 11:24:23 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

void		assign_normal_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '/')
		i++;
	(*obj)->normal.x = ft_atoi(str);
	while (str[i] != '/')
		i++;
	(*obj)->normal.y = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	(*obj)->normal.z = ft_atoi(&str[i + 1]);
}

void		assign_dir_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '/')
		i++;
	(*obj)->dir.x = ft_atoi(str);
	while (str[i] != '/')
		i++;
	(*obj)->dir.y = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	(*obj)->dir.z = ft_atoi(&str[i + 1]);
}

void		assign_pos_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '/')
		i++;
	(*obj)->pos.x = ft_atoi(str);
	while (str[i] != '/')
		i++;
	(*obj)->pos.y = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	(*obj)->pos.z = ft_atoi(&str[i + 1]);
}

void		assign_color_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '/')
		i++;
	(*obj)->color.r = ft_atoi(str);
	while (str[i] != '/')
		i++;
	(*obj)->color.g = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	(*obj)->color.b = ft_atoi(&str[i + 1]);
}

void		assign_lightcolor_p(t_light **obj, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '/')
		i++;
	(*obj)->color.r = ft_atoi(str);
	while (str[i] != '/')
		i++;
	i++;
	(*obj)->color.g = ft_atoi(&str[i + 1]);
	while (str[i] != '/')
		i++;
	(*obj)->color.b = ft_atoi(&str[i + 1]);
}
