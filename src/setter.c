/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:17:05 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	set_object_type(char *name, t_object *obj)
{
	if (ft_strcmp(name, "sphere") == 0)
		obj->type = SPHERE;
	else if (ft_strcmp(name, "cone") == 0)
		obj->type = CONE;
	else if (ft_strcmp(name, "cylindre") == 0)
		obj->type = CYLINDER;
	else if (ft_strcmp(name, "plane") == 0)
		obj->type = PLANE;
}

void	set_object_param(char *value, char *data, t_object *obj)
{
	if (ft_strcmp(value, "radius") == 0)
		obj->radius = ft_atof(data);
	else if (ft_strcmp(value, "height") == 0)
		obj->height = ft_atof(data);
	else if (ft_strcmp(value, "cut") == 0)
		assign_cut_p(&obj, data);
	else if (ft_strcmp(value, "pos") == 0)
		assign_pos_p(&obj, data);
	else if (ft_strcmp(value, "dir") == 0)
		assign_dir_p(&obj, data);
	else if (ft_strcmp(value, "normal") == 0)
		assign_normal_p(&obj, data);
	else if (ft_strcmp(value, "color") == 0)
		assign_color_p(&obj, data);
	else if (ft_strcmp(value, "shine") == 0)
		obj->shine = ft_atof(data);
	else if (ft_strcmp(value, "refraction") == 0)
		obj->refraction = ft_atof(data);
	else if (ft_strcmp(value, "reflect") == 0)
		obj->reflect = ft_atof(data);
	else if (ft_strcmp(value, "checkered") == 0)
		obj->checkered = ft_atof(data);
	else
		ft_putendl_fd("ERROR PARSING DATA", 2);
}

void	set_light_type(char *name, t_light *obj)
{
	if (ft_strcmp(name, "normal") == 0)
		obj->type = NORMAL;
}

void	set_light_param(char *value, char *data, t_light *obj)
{
	if (!obj)
		return ;
	if (ft_strcmp(value, "pos") == 0)
		assign_pos_light(obj, data, 0);
	else if (ft_strcmp(value, "color") == 0)
		assign_lightcolor_p(&obj, data);
	else if (ft_strcmp(value, "dir") == 0)
		assign_pos_light(obj, data, 1);
	else if (ft_strcmp(value, "intensity") == 0)
		obj->intensity = ft_atof(data);
	else if (ft_strcmp(value, "ambiant") == 0)
		obj->ambiant = ft_atof(data);
	else
		ft_putendl_fd("ERROR PARSING DATA", 2);
}
