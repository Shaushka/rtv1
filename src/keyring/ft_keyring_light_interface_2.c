/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_light_interface_2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:46 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

void	ft_print_pending_lightpos_modif(t_light *l, t_env *e)
{
	char	*li;
	char	*tmp1;
	char	*tmp2;
	char	*swp;

	if (!l)
		return ;
	tmp1 = ft_itoa((int)(l->pos.x));
	tmp2 = ft_itoa((int)(l->pos.y));
	li = ft_strjoin("Pending light position status : x = ", tmp1);
	swp = ft_strjoin(li, " y = ");
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&swp);
	swp = ft_strjoin(li, " z = ");
	tmp1 = ft_itoa((int)(l->pos.z));
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&swp);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, 10 + INTER_W,
					(1. / 7 * INTER_H), 0x0, li);
	ft_strdel(&li);
}

void	ft_print_pending_lightdir_modif(t_light *l, t_env *e)
{
	char	*li;
	char	*tmp1;
	char	*tmp2;
	char	*swp;

	if (!l)
		return ;
	tmp1 = ft_itoa((int)(l->dir.x));
	tmp2 = ft_itoa((int)(l->dir.y));
	li = ft_strjoin("Pending light direction status : x = ", tmp1);
	swp = ft_strjoin(li, " y = ");
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&swp);
	swp = ft_strjoin(li, " z = ");
	tmp1 = ft_itoa((int)(l->dir.z));
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&swp);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, 10 + INTER_W,
					(3. / 7 * INTER_H), 0x0, li);
	ft_strdel(&li);
}

void	ft_print_pending_lightcol_modif(t_light *l, t_env *e)
{
	char	*li;
	char	*tmp1;
	char	*tmp2;
	char	*swp;

	if (!l)
		return ;
	tmp1 = ft_itoa((int)(l->color.r));
	tmp2 = ft_itoa((int)(l->color.g));
	li = ft_strjoin("Pending light color status : r = ", tmp1);
	swp = ft_strjoin(li, " g = ");
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp2);
	ft_strdel(&tmp1);
	ft_strdel(&tmp2);
	ft_strdel(&swp);
	swp = ft_strjoin(li, " b = ");
	tmp1 = ft_itoa((int)(l->color.b));
	ft_strdel(&li);
	li = ft_strjoin(swp, tmp1);
	ft_strdel(&tmp1);
	ft_strdel(&swp);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, 10 + INTER_W,
					(5. / 7 * INTER_H), 0x0, li);
	ft_strdel(&li);
}

void	ft_print_pending_lightint_modif(t_light *l, t_env *e)
{
	char	*tmp1;
	char	*li;

	tmp1 = ft_itoa((int)(l->intensity * 100));
	li = ft_strjoin("Pending light intensity status : i = 0.001 * ", tmp1);
	ft_strdel(&tmp1);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, 10 + INTER_W,
					INTER_H * (6. / 7.), 0x0, li);
	ft_strdel(&li);
}

void	ft_print_selected_light(t_env *e)
{
	char	*tmp1;
	char	*li;

	if (!e->scene->light)
		return ;
	tmp1 = ft_itoa((int)(e->key.selected_light));
	li = ft_strjoin("selected_light : ", tmp1);
	ft_strdel(&tmp1);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, 10 + INTER_W,
					10 + INTER_H, 0x0, li);
	ft_strdel(&li);
}
