/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_light_interface_cmd.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:18:22 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 21:26:38 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
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

	swp = ft_get_light_at_nb(e->key.selected_light, e->lights);
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
	swp->color.r += mod == 513  && swp->color.r + 10 <= 255 ? 10 : 0;
	swp->color.r -= mod == 514  && swp->color.r - 10 >= 000 ? 10 : 0;
	swp->color.g += mod == 515  && swp->color.g + 10 <= 255 ? 10 : 0;
	swp->color.g -= mod == 516  && swp->color.g - 10 >= 000 ? 10 : 0;
	swp->color.b += mod == 517  && swp->color.b + 10 <= 255 ? 10 : 0;
	swp->color.b -= mod == 518  && swp->color.b - 10 >= 000 ? 10 : 0;
	swp->intensity += mod == 519 && swp->intensity + 0.1 <= 1 ? 0.1 : 0;
	swp->intensity -= mod == 520 && swp->intensity - 0.1 >= 0 ? 0.1 : 0;
}
