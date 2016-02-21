/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:28 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

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

void		normal(t_object *node)
{
	char	*tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la normale :\n");
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
