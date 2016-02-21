/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_object_interface_2.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:59 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		ft_get_om_cmd_interface(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > 0 && y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 1);
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > INTER_H * (1. / 2.) &&
		y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 2);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) && y > 0 &&
		y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 3);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y > INTER_H * (1. / 2.) && y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 4);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > 0 && y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 5);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > INTER_H * (1. / 2.) && y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 6);
	return (e->key.mode);
}

void	ft_mod_grouped_obj(t_env *e, int mod, int index)
{
	t_object	*swp;

	swp = e->scene->l_obj;
	while (swp)
	{
		if (swp->bundle == index)
		{
			swp->pos.x += mod == 801 ? 1 : 0;
			swp->pos.x -= mod == 802 ? 1 : 0;
			swp->pos.y += mod == 803 ? 1 : 0;
			swp->pos.y -= mod == 804 ? 1 : 0;
			swp->pos.z += mod == 805 ? 1 : 0;
			swp->pos.z -= mod == 806 ? 1 : 0;
		}
		swp = swp->next;
	}
}

int		ft_get_new_bundle_nb(t_env *e)
{
	t_object	*swp;
	int			ret;

	swp = e->scene->l_obj;
	ret = 0;
	while (swp)
	{
		if (ret == swp->bundle)
		{
			ret++;
			swp = e->scene->l_obj;
		}
		else
			swp = swp->next;
	}
	return (ret);
}
