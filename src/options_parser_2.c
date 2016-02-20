#include "rtv1.h"
#include "libft.h"

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
	(*obj)->normal = unit_vector((*obj)->normal);
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
	(*obj)->dir = unit_vector((*obj)->dir);
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
