/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 12:50:05 by mgras             #+#    #+#             */
/*   Updated: 2016/02/19 16:37:39 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

/*
**	Quick uitlity for freeing shit
**	Could be so wrong btw so watch out
*/

char	**ft_free_char_tab(char **del)
{
	int		ss;

	ss = 0;
	if (del == NULL)
		return (NULL);
	while (del[ss])
	{
		if (del[ss])
			ft_strdel(&(del[ss]));
		ss++;
	}
	free(del);
	del = NULL;
	return (del);
}

int		**ft_free_int_tab(int **del, int len)
{
	int		ss;

	ss = 0;
	if (del == NULL)
		return (NULL);
	while (ss != len)
	{
		if (del[ss])
			free(del[ss]);
		ss++;
	}
	free(del);
	del = NULL;
	return (del);
}

void	ft_free_obj_lst(t_object *start)
{
	t_object	*swp;

	while (start)
	{
		swp = start->next;
		free(start);
		start = NULL;
		start = swp;
	}
}

void	ft_free_light_lst(t_light *start)
{
	t_light	*swp;

	while (start)
	{
		swp = start->next;
		free(start);
		start = NULL;
		start = swp;
	}
}

void	ft_free_one_node(t_node *one_del)
{
	if (one_del->value)
		ft_strdel(&(one_del->value));
	if (one_del->type)
		ft_strdel(&(one_del->type));
	free(one_del);
}

void	ft_free_node_lst(t_node *start)
{
	t_node	*swp;

	swp = start;
	while (start)
	{
		swp = start->next;
		if (start->value)
			ft_strdel(&(start->value));
		if (start->type)
			ft_strdel(&(start->type));
		free(start);
		start = NULL;
		start = swp;
	}
}

void	ft_free_parse(t_parse *del)
{
	if (del->name)
		ft_strdel(&(del->name));
	//ft_free_node_lst(del->nodes);
	free(del);
}
