/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_light_interface_cmd.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:50 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		ft_get_lm_cmd_interface_4(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 2.) &&
		y >= (double)INTER_H * (6. / 7.) && y <= (double)INTER_H)
		return (e->key.mode = 500 + 19);
	if (x >= INTER_W * (1. / 2.) && x <= INTER_W &&
		y >= (double)INTER_H * (6. / 7.) && y <= (double)INTER_H)
		return (e->key.mode = 500 + 20);
	return (e->key.mode);
}

int		ft_get_lm_cmd_interface_3(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) &&
		y >= (double)INTER_H * (4. / 7.) && y <= (double)INTER_H * (5. / 7.))
		return (e->key.mode = 500 + 13);
	if (x >= 0 && x <= INTER_W * (1. / 3.) &&
		y >= (double)INTER_H * (5. / 7.) && y <= (double)INTER_H * (6. / 7.))
		return (e->key.mode = 500 + 14);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y >= (double)INTER_H * (4. / 7.) && y <= (double)INTER_H * (5. / 7.))
		return (e->key.mode = 500 + 15);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y >= (double)INTER_H * (5. / 7.) && y <= (double)INTER_H * (6. / 7.))
		return (e->key.mode = 500 + 16);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W * (3. / 3.) &&
		y >= (double)INTER_H * (4. / 7.) && y <= (double)INTER_H * (5. / 7.))
		return (e->key.mode = 500 + 17);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W * (3. / 3.) &&
		y >= (double)INTER_H * (5. / 7.) && y <= (double)INTER_H * (6. / 7.))
		return (e->key.mode = 500 + 18);
	return (ft_get_lm_cmd_interface_4(x, y, e));
}

int		ft_get_lm_cmd_interface_2(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) &&
		y >= (double)INTER_H * (2. / 7.) && y <= (double)INTER_H * (3. / 7.))
		return (e->key.mode = 500 + 07);
	if (x >= 0 && x <= INTER_W * (1. / 3.) &&
		y >= (double)INTER_H * (3. / 7.) && y <= (double)INTER_H * (4. / 7.))
		return (e->key.mode = 500 + 8);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y >= (double)INTER_H * (2. / 7.) && y <= (double)INTER_H * (3. / 7.))
		return (e->key.mode = 500 + 9);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y >= (double)INTER_H * (3. / 7.) && y <= (double)INTER_H * (4. / 7.))
		return (e->key.mode = 500 + 10);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W * (3. / 3.) &&
		y >= (double)INTER_H * (2. / 7.) && y <= (double)INTER_H * (3. / 7.))
		return (e->key.mode = 500 + 11);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W * (3. / 3.) &&
		y >= (double)INTER_H * (3. / 7.) && y <= (double)INTER_H * (4. / 7.))
		return (e->key.mode = 500 + 12);
	return (ft_get_lm_cmd_interface_3(x, y, e));
}

int		ft_get_lm_cmd_interface(int x, int y, t_env *e)
{
	if (!e->scene->light)
		return (5);
	if (x >= 0 && x <= INTER_W * (1. / 3.) &&
		y >= 0 && y <= (double)INTER_H * (1. / 7.))
		return (e->key.mode = 500 + 01);
	if (x >= 0 && x <= INTER_W * (1. / 3.) &&
		y >= (double)INTER_H * (1. / 7.) && y <= (double)INTER_H * (2. / 7.))
		return (e->key.mode = 500 + 02);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y >= 0 && y <= (double)INTER_H * (1. / 7.))
		return (e->key.mode = 500 + 03);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y >= (double)INTER_H * (1. / 7.) && y <= (double)INTER_H * (2. / 7.))
		return (e->key.mode = 500 + 04);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W * (3. / 3.) &&
		y >= 0 && y <= (double)INTER_H * (1. / 7.))
		return (e->key.mode = 500 + 05);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W * (3. / 3.) &&
		y >= (double)INTER_H * (1. / 7.) && y <= (double)INTER_H * (2. / 7.))
		return (e->key.mode = 500 + 06);
	return (ft_get_lm_cmd_interface_2(x, y, e));
}

void	ft_mod_light_inc(t_env *e, int mod)
{
	t_light		*swp;

	swp = ft_get_light_at_nb(e->key.selected_light, e->scene->light);
	if (!swp)
		return ;
	if (swp->bundle != -1)
	{
		ft_mod_grouped_light(e, mod, swp->bundle);
		return ;
	}
	ft_set_one_light(swp, mod);
}
