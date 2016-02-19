#include "rtv1.h"

void	error_in_parse(char *str)
{
	perror(str);
	ft_wait_exit(1);
}

void	print_vector(t_vector vec, char *pre)
{
	ft_putstr(pre);
	printf("x = %f, y = %f, z = %f\n", vec.x, vec.y, vec.z);
}

void	print_color(t_color col, char *pre)
{
	ft_putstr(pre);
	printf("R = %d, G = %d, B = %d\n", col.r, col.g, col.b);
}

void	print_result(t_parse *parse)
{
	int			i;
	t_object	*obj;
	t_light		*light;

	obj = parse->obj;
	i = 0;
	ft_putendl(parse->name);
	while (obj)
	{
		ft_putchar('\n');
		ft_putnbr(obj->type);
		print_color(obj->color, "\n\tcolor : ");
		print_vector(obj->pos, "\n\tpos : ");
		print_vector(obj->dir, "\n\tdir : ");
		print_vector(obj->normal, "\n\tnormal : ");
		printf("\n\tradius : %f\theight : %f\n\tshine: %f\n", obj->radius, obj->height, obj->shine);
		//reflect
		//checkered
		obj = obj->next;
		i++;
	}
	ft_putstr("nbr de object = ");
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
	i = 0;
	light = parse->light;
	while (light)
	{
		ft_putnbr(light->type);
		print_vector(light->pos, "\n\tpos : ");
		print_vector(light->dir, "\n\tdir : ");
		print_color(light->color, "\n\tcolor : ");
		printf("\n\tintensity : %f\n", light->intensity);
		ft_putchar('\n');
		light = light->next;
		i++;
	}
	ft_putstr("nombre de light = ");
	ft_putnbr(i);
	ft_putchar('\n');
}
