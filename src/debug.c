#include "rtv1.h"

void	error_in_parse(char *str)
{
	perror(str);
	exit(1);
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
