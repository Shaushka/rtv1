#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

/*
**	Quick uitlity for freeing shit
**	Could be so wrong btw so watch out
*/

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
	free(del);
}
