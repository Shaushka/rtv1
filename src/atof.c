#include "rtv1.h"

float	power(float value, int times)
{
	float new_val;

	new_val = value;
	while (times > 0)
	{
		new_val *= value;
		times--;
	}
	return(new_val);
}


float	ft_atof(char *number)
{
	float f;

	int 	i;
	int	u_len;
	int	p_pos;

	i = 0;
	while (number[i] && number[i] != '.')
		i++;
	u_len = ft_strlen(number) - i;
	p_pos = i;
	int part1 = ft_atoi(ft_strsub(number, 0, p_pos));
	int part2 = ft_atoi(ft_strsub(number, p_pos + 1, u_len));
	f = (float)part1 + (float)part2 / (power(10, u_len - 2));
	return(f);
}
