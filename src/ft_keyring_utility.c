/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_utility.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:44:46 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 20:13:46 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

void		ft_get_next_light(t_env	*e)
{
	t_light		*swp;

	swp = ft_get_light_at_nb(e->key.selected_light + 1, e->lights);
	if (swp)
		e->key.selected_light++;
	else
		e->key.selected_light = 0;
}

t_light		*ft_get_light_at_nb(int nb, t_light *s)
{
	t_light	*swp;
	int		ss;

	ss = 0;
	swp = s;
	while (ss != nb)
	{
		ss++;
		swp = swp->next;
	}
	return (swp);
}
