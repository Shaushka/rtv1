#include "rtv1.h"

void	error_in_parse(char *str)
{
	perror(str);
	exit(1);
}

void	print_nodes(t_node *nodes)
{
	/*if pour avancer de un puisque ne fonctionne pas dans include node*/
	/* on peut mettre une compteur de premiere fois si necessaire */
	if (nodes && (nodes = nodes->next) != NULL)
	{
		while (nodes)
		{
			ft_putnbr(nodes->beg);
			ft_putchar('\n');
			ft_putchar(nodes->type);
			ft_putchar('\n');
			nodes = nodes->next;
		}
	}
}

void	print_result(t_parse *parse)
{
	int	i;

	i = 0;
	ft_putendl(parse->name);
	while (parse->obj)
	{
		ft_putnbr(parse->obj->type);
		ft_putchar('\n');
		parse->obj = parse->obj->next;
		i++;
	}
	ft_putstr("i = ");
	ft_putnbr(i);
	ft_putchar('\n');
}
