/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:45 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				get_instr(char *get, t_parse *parse, t_env *e)
{
	t_node	*tmp;
	char	**tab;
	int		k;

	if ((parse->nodes = (t_node *)malloc(sizeof(t_node))) == NULL)
		error_in_parse("Error: malloc t_node");
	parse->nodes->type = NULL;
	parse->nodes->value = NULL;
	tmp = parse->nodes;
	tab = ft_strsplit(get, '<');
	k = 0;
	while (tab[k] && (k < 1 || tab[k - 1]) && ((k < 2) || tab[k - 2]))
		k = set_node(&(parse->nodes), k, tab);
	if (tab && *tab)
	{
		recup_nodes(tmp, parse, e);
		ft_free_node_lst(tmp);
		tab = tab ? ft_free_char_tab(tab) : tab;
	}
	else
	{
		tab = tab ? ft_free_char_tab(tab) : tab;
		ft_putendl_fd("ERROR file parsing", 2);
		ft_wait_exit(1);
	}
}
