/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_light_interface_3.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:48 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	ft_mod_grouped_light(t_env *e, int mod, int index)
{
	t_light		*swp;

	swp = e->lights;
	while (swp)
	{
		if (swp->bundle == index)
			ft_set_one_light(swp, mod);
		swp = swp->next;
	}
}

int		ft_get_new_bundle_nb_l(t_env *e)
{
	t_light		*swp;
	int			ret;

	swp = e->lights;
	ret = 0;
	while (swp)
	{
		if (ret == swp->bundle)
		{
			ret++;
			swp = e->lights;
		}
		else
			swp = swp->next;
	}
	return (ret);
}

void	ft_set_one_light(t_light *swp, int mod)
{
	swp->pos.x += mod == 501 ? 1 : 0;
	swp->pos.x -= mod == 502 ? 1 : 0;
	swp->pos.y += mod == 503 ? 1 : 0;
	swp->pos.y -= mod == 504 ? 1 : 0;
	swp->pos.z += mod == 505 ? 1 : 0;
	swp->pos.z -= mod == 506 ? 1 : 0;
	swp->dir.x += mod == 507 ? 1 : 0;
	swp->dir.x -= mod == 508 ? 1 : 0;
	swp->dir.y += mod == 509 ? 1 : 0;
	swp->dir.y -= mod == 510 ? 1 : 0;
	swp->dir.z += mod == 511 ? 1 : 0;
	swp->dir.z -= mod == 512 ? 1 : 0;
	swp->color.r += mod == 513 && swp->color.r + 10 <= 255 ? 10 : 0;
	swp->color.r -= mod == 514 && swp->color.r - 10 >= 000 ? 10 : 0;
	swp->color.g += mod == 515 && swp->color.g + 10 <= 255 ? 10 : 0;
	swp->color.g -= mod == 516 && swp->color.g - 10 >= 000 ? 10 : 0;
	swp->color.b += mod == 517 && swp->color.b + 10 <= 255 ? 10 : 0;
	swp->color.b -= mod == 518 && swp->color.b - 10 >= 000 ? 10 : 0;
	swp->intensity += mod == 519 && swp->intensity + 0.1 <= 1 ? 0.1 : 0;
	swp->intensity -= mod == 520 && swp->intensity - 0.1 >= 0 ? 0.1 : 0;
}
