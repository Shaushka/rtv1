#include "rtv1.h"

void	set_object_type(char *name, t_object *obj)
{
	if (ft_strcmp(name, "sphere") == 0)
		obj->type = SPHERE;
	else if (ft_strcmp(name, "cone") == 0)
		obj->type = CONE;
	else if (ft_strcmp(name, "cylindre") == 0)
		obj->type = CYLINDER;
	else if (ft_strcmp(name, "plan") == 0)
		obj->type = PLANE;
/*	else if (ft_strcmp(name, "light") == 0)
		obj->type = LIGHT;
	else if (ft_strcmp(name, "camera") == 0)
		obj->type = CAMERA;*/
}

void	set_object_param(char *value, char *data, t_object *obj)
{
	// diviser heght par 2 ?
	if (ft_strcmp(value, "radius") == 0)
		obj->radius = ft_atof(data);
	else if (ft_strcmp(value, "height") == 0)
		obj->height = ft_atof(data);
	else if (ft_strcmp(value, "pos") == 0)
		assign_pos(obj, data);
	else if (ft_strcmp(value, "normal") == 0)
		assign_normal(obj, data);
	else if (ft_strcmp(value, "color") == 0)
		assign_color(&obj->color, data);
	else if (ft_strcmp(value, "shine") == 0)
		obj->shine = ft_atof(data);
//	else if (ft_strcmp(value, "dir") == 0)
//		obj->dir = assign_pos(obj, data);
}
