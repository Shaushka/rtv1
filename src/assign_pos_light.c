#include <stdlib.h>
#include <unistd.h>
#include "../../includes/rtv1.h"
#include "../../libft/includes/libft.h"

void			assign_pos_light(t_light *node, char *str, int n)
{
	int			i;

	i = 0;
	if (!node)
		return ;
	if (n == 0)
		node->pos.x = ft_atoi(str);
	else
		node->dir.x = ft_atoi(str);
	while (str[i] != '/')
		i++;
	if (n == 0)
		node->pos.y = ft_atoi(&str[i + 1]);
	else
		node->dir.y = ft_atoi(&str[i + 1]);
	i++;
	while (str[i] != '/')
		i++;
	if (n == 0)
		node->pos.z = ft_atoi(&str[i + 1]);
	else
		node->dir.z = ft_atoi(&str[i + 1]);
}
