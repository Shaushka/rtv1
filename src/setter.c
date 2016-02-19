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
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		obj->radius = ft_atof(data);
//		ft_putnbr(obj->radius);
//		ft_putchar('\n');
	}
	else if (ft_strcmp(value, "height") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		obj->height = ft_atof(data);
//		ft_putnbr(obj->height);
//		ft_putchar('\n');
	}
	else if (ft_strcmp(value, "pos") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		assign_pos_p(&obj, data);
//		printf("%f\n", obj->pos.x);
//		printf("%f\n", obj->pos.y);
//		printf("%f\n", obj->pos.z);
	}
	else if (ft_strcmp(value, "dir") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		assign_dir_p(&obj, data);
//		printf("%f\n", obj->pos.x);
//		printf("%f\n", obj->pos.y);
//		printf("%f\n", obj->pos.z);
	}
	else if (ft_strcmp(value, "normal") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		assign_normal_p(&obj, data);
//		printf("%f\n", obj->normal.x);
//		printf("%f\n", obj->normal.y);
//		printf("%f\n", obj->normal.z);
	}
	else if (ft_strcmp(value, "color") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		assign_color_p(&obj, data);
//		ft_putnbr(obj->color.r);
//		ft_putchar('\n');
//		ft_putnbr(obj->color.g);
//		ft_putchar('\n');
//		ft_putnbr(obj->color.b);
//		ft_putchar('\n');
	}
	else if (ft_strcmp(value, "shine") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		obj->shine = ft_atof(data);
//		ft_putnbr(obj->shine);
//		ft_putchar('\n');
	}
	else if (ft_strcmp(value, "refraction") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		obj->shine = ft_atof(data);
//		ft_putnbr(obj->shine);
//		ft_putchar('\n');
	}
	else if (ft_strcmp(value, "reflect") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		obj->shine = ft_atof(data);
//		ft_putnbr(obj->shine);
//		ft_putchar('\n');
	}
	else if (ft_strcmp(value, "checkered") == 0)
	{
//		ft_putstr("data = ");
//		ft_putendl(data);
		obj->shine = ft_atof(data);
//		ft_putnbr(obj->shine);
//		ft_putchar('\n');
	}
	else
		ft_putendl_fd("ERROR PARSING DATA", 2);
//	else if (ft_strcmp(value, "dir") == 0)
//		obj->dir = assign_dir_p(&obj, data);
}

void	set_light_type(char *name, t_light *obj)
{
	if (ft_strcmp(name, "normal") == 0)
		obj->type = NORMAL;
}

void	set_light_param(char *value, char *data, t_light *obj)
{
	if (ft_strcmp(value, "pos") == 0)
		assign_pos_light(obj, data, 0);
	else if (ft_strcmp(value, "color") == 0)
		assign_lightcolor_p(&obj, data);
	else if (ft_strcmp(value, "dir") == 0)
		assign_pos_light(obj, data, 1);
	else if (ft_strcmp(value, "intensity") == 0)
		obj->intensity = ft_atof(data);
	else
		ft_putendl_fd("ERROR PARSING DATA", 2);
//	else if (ft_strcmp(value, "dir") == 0)
//		obj->dir = assign_pos(obj, data);
}
