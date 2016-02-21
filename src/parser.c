/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:43 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			newnode(char **tab, int pos, t_node **new_node)
{
	int				t;

	t = get_the_mark(tab[pos]);
	(*new_node)->type = ft_strsub(tab[pos], 0, t);
	(*new_node)->value = ft_strsub(tab[pos], t + 1, ft_strlen(tab[pos]));
	(*new_node)->next = NULL;
}

char				*ft_del_and_trim(char **swp, char **tab, int pos)
{
	ft_strdel(swp);
	return (ft_strtrim(tab[pos]));
}

static void			ft_nodes(t_node **nodes, t_node **new_node)
{
	(*nodes)->next = *new_node;
	(*nodes) = (*nodes)->next;
}

static	int			ft_islight(t_fam *n, int pos)
{
	*n = LIGHT;
	return (pos + 1);
}

int					set_node(t_node **nodes, int pos, char **tab)
{
	t_node			*new_node;
	char			*swp;
	static t_fam	n = NONE;

	swp = ft_strtrim(tab[pos]);
	if (check_shit(tab[pos]) == 1 || ft_strncmp(swp, "objet>", 6) == 0)
	{
		n = OBJECT;
		return (pos + 1);
	}
	swp = ft_del_and_trim(&swp, tab, pos);
	if (check_shit(tab[pos]) == 1 || ft_strncmp(swp, "light>", 6) == 0)
		return (ft_islight(&n, pos));
	ft_strdel(&swp);
	if ((new_node = (t_node *)malloc(sizeof(t_node))) == NULL)
		error_in_parse("Error: malloc new t_node");
	else
	{
		newnode(tab, pos, &new_node);
		new_node->family = n;
		ft_nodes(nodes, &new_node);
	}
	return (pos + 2);
}
