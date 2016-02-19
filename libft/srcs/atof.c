/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:40:03 by mguillon          #+#    #+#             */
/*   Updated: 2016/02/19 18:42:38 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

float	power(float value, int times)
{
	float new_val;

	new_val = value;
	while (times > 0)
	{
		new_val *= value;
		times--;
	}
	return (new_val);
}

int		ft_atof_p1(char *number, int p_pos)
{
	char	*tmp;
	int		ret;

	tmp = ft_strsub(number, 0, p_pos);
	ret = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (ret);
}

int		ft_atof_p2(char *number, int p_pos, int u_len)
{
	char	*tmp;
	int		ret;

	tmp = ft_strsub(number, p_pos + 1, u_len);
	ret = ft_atoi(tmp);
	ft_strdel(&tmp);
	return (ret);
}

float	ft_atof(char *number)
{
	float	f;
	int		i;
	int		u_len;
	int		p_pos;

	i = 0;
	while (number[i] && number[i] != '.')
		i++;
	u_len = ft_strlen(number) - i;
	p_pos = i;
	f = (float)ft_atof_p1(number, p_pos) +
		(float)ft_atof_p2(number, p_pos, u_len) /
		(power(10, u_len - 2));
	return (f);
}
