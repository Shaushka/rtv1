#include "parser.h"

/*
* reprise des fonctions de Marion dans interactive notamment
*/

void		assign_color(t_color *color, char *str)
{
	int			i;

	i = 0;
	color->r = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	color->g = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	color->b = ft_atoi(cut_pos(str, i));
}

void		assign_normal(t_object *node, char *str)
{
	int			i;

	i = 0;
	node->normal.x = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	node->normal.y = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	node->normal.z = ft_atoi(cut_pos(str, i));
}

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


char		**remove_spaces(char *str, int i, char **clean)
{
	int j;

	j = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			*clean[j] = str[i];
			i++;
			j++;
		}
	}
	return (clean);
}

char		*no_more_spaces(char *str)
{
	char	*clean;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			j++;
			i++;
		}
		else
			i++;
	}
	len -= j;
	clean = malloc(sizeof(char) * (len + 1));
	return (*remove_spaces(str, i, &clean));
}

void		separators(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
		{
			i++;
			while (str[i] == '/')
			{
				str[i] = ' ';
				j++;
			}
		}
		else
			i++;
	}
}

void			init_obj(t_object *node)
{
	node->next = NULL;
	node->pos = set_vector(node->pos, 0, 0, 0);
	node->normal = set_vector(node->pos, 0, 0, 0);
	node->radius = 0;
	node->height = 0;
}

t_vector	set_vector(t_vector v, float x, float y, float z)
{
	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_object		*create_object()
{
	t_object *a;
	//t_object *b;

	a = (t_object*)malloc(sizeof(t_object));
	init_obj(a);
/*	if (e->scene->l_obj == NULL)
	{
		e->scene->l_obj = a;
		if (e->scene->l_obj == NULL)
			return (NULL);
	}
	else
	{
		b = e->scene->l_obj;
		while (b->next != NULL)
			b = b->next;
		b->next = a;
	}*/
	return (a);
}


int				is_slashes_and_digits(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '/')
			return (0);
		else
			i++;
	}
	return (1);
}

int				is_vector(char *str)
{
	int			i;
	int			s;
	int			n;

	i = 0;
	s = 0;
	n = 0;
	if (!ft_isdigit(str[0]))
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			n++;
			while (ft_isdigit(str[i]) && str[i] != '\0')
				i++;
		}
		if (str[i++] == '/')
			s++;
	}
	if (n == 3 && s == 2)
		return (1);
	else
		return (0);
}

int				correct_input(char *str)
{
	char		*clean;
	char		*final;

	clean = no_more_spaces(str);
	if (is_slashes_and_digits(clean))
	{
		separators(clean);
		final = no_more_spaces(clean);
		free(clean);
		if (is_vector(final))
			return (1);
	}
	return (0);
}
