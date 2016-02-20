#include "rtv1.h"

void	error_in_parse(char *str)
{
	perror(str);
	ft_wait_exit(1);
}

void	print_vector(t_vector vec, char *pre)
{
	ft_putstr(pre);
	printf("x = %f, y = %f, z = %f\n", vec.x, vec.y, vec.z);
}

void	print_color(t_color col, char *pre)
{
	ft_putstr(pre);
	printf("R = %d, G = %d, B = %d\n", col.r, col.g, col.b);
}
