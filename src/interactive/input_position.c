/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:31 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

char			*cut_pos(char *str, int i)
{
	char		*tmp;
	int			j;
	int			k;

	k = i;
	j = 0;
	while (str[i] != '/' && str[i] != '\0' && str[i] != '\n')
	{
		i++;
		j++;
	}
	tmp = malloc(sizeof(char) * (j + 1));
	i = k;
	while (str[i] != '/' && str[i] != '\0' && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\n';
	return (tmp);
}

char			*cleanit(char *str)
{
	char *clean;

	clean = no_more_spaces(str);
	separators(clean);
	return (no_more_spaces(clean));
}

int				check_values(char *str, int min, int max)
{
	int			i;
	int			x;
	char		*clean;

	i = 0;
	clean = cleanit(str);
	x = ft_atoi(cut_pos(clean, i));
	if (x < min || x > max)
		return (0);
	while (ft_isdigit(clean[i]))
		i++;
	i++;
	x = ft_atoi(cut_pos(clean, i));
	if (x < min || x > max)
		return (0);
	while (ft_isdigit(clean[i]))
		i++;
	i++;
	x = ft_atoi(cut_pos(clean, i));
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
	ft_putstr(tmp);
	remove_bn(&tmp);
	printf("POS :	tmp = \"%s\"\n", tmp);
	if (check_values(tmp, 0, 100))
	{
		printf("POS :	Debut d'assign_pos\n");
		assign_pos(node, tmp);
	}
	free(tmp);
}
