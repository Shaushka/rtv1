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

void	ft_free_parse(t_parse *del)
{
	if (del->name)
		ft_strdel(&(del->name));
	free(del);
}
