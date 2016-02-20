#include <stdlib.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

void		assign_cut_p(t_object **obj, char *str)
{
	int			i;

	i = 0;
	while (str[i] != '/')
		i++;
	(*obj)->cut.x = ft_atoi(str);
	while (str[i] != '/')
		i++;
	(*obj)->cut.y = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	(*obj)->cut.z = ft_atoi(&str[i + 1]);
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
	(*obj)->color.g = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	(*obj)->color.b = ft_atoi(&str[i + 1]);
}
