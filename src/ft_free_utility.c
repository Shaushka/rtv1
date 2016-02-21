/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:37 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
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
