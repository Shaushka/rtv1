#include <stdlib.h>
#include <unistd.h>
#include "../../includes/rtv1.h"
#include "../../libft/includes/libft.h"

char			*cut_pos(char *str, int i)
{
	char		*tmp;
	int			j;

	j = 0;
	while (str[i] != '/')
	{
		i++;
		j++;
	}
	tmp = malloc(sizeof(char) * (j + 1));
	i = 0;
	while (str[i] != '/')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\n';
	return (tmp);
}

int				check_values(char *str, int min, int max)
{
	int			i;
	int			x;

	i = 0;
	printf("Valeur de str dans check_values : \"%s\"\n", str);
	x = ft_atoi(cut_pos(str, i));
	if (x < min || x > max)
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	i++;
	x = ft_atoi(cut_pos(str, i));
	if (x < min || x > max)
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	i++;
	x = ft_atoi(cut_pos(str, i));
	if (x < min || x > max)
		return (0);
	return (1);
}

void			assign_pos(t_object *node, char *str)
{
	int			i;

	i = 0;
	node->pos.x = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	node->pos.y = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	node->pos.z = ft_atoi(cut_pos(str, i));
}

void			position(t_object *node)
{
	char		*tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la position :\n");
	ft_putstr("Format : x/y/z (entre 1 et 100) : ");
	read(0, tmp, 200);
	while (!correct_input(tmp))
	{
		ft_bzero(tmp, 200);
		ft_putstr("Entrez la position sous la forme x/y/z : ");
		read(0, tmp, 200);
	}
	if (check_values(tmp, 0, 100))
		assign_pos(node, tmp);
	free(tmp);
}
