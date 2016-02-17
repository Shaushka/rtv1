/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:55:14 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 17:16:06 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

/*
**	mode -1 = all is hidden, will go to mode 1 when respawned whith keybinding
**	mode 0 = all must be hidden (useless ?)
**	mode 1 = must spaw main menu (useless ?)
**	mode 2 = main menu is up waiting for command
**	mode 3 = must spawn camera menu (useless ?)
**	mode 4 = must spaw light menu (useless ?)
**	mode 5 = light menu is up and waiting for command
**	mode 6 = camera menu is up and waiting for command
**		**mode 600 + 01 = cam.pos.x++;
**		**mode 600 + 02 = cam.pos.x--;
**		**mode 600 + 03 = cam.pos.y++;
**		**mode 600 + 04 = cam.pos.y--;
**		**mode 600 + 05 = cam.pos.z++;
**		**mode 600 + 06 = cam.pos.z--;
**		**mode 600 + 07 = cam.dir.x++;
**		**mode 600 + 08 = cam.dir.x--;
**		**mode 600 + 09 = cam.dir.y++;
**		**mode 600 + 10 = cam.dir.y--;
**		**mode 600 + 11 = cam.dir.z++;
**		**mode 600 + 12 = cam.dir.z--;
**
**	mode 7 = must spaw obj menu (useless ?)
**	mode 8 = obj menu is up and waiting for command
*/

int		ft_get_mm_cmd_interface(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W && y >= 0 && y <= (double)INTER_H * (1. / 3.))
		return (e->key.mode = 3);
	if (x >= 0 && x <= INTER_W && y >= (double)INTER_H * (1. / 3.) &&
									y <= (double)INTER_H * (2. / 3.))
		return (e->key.mode = 4);
	if (x >= 0 && x <= INTER_W && y >= (double)INTER_H * (2. / 3.) &&
									y <= (double)INTER_H * (3. / 3.))
		return (e->key.mode = 7);
	return (e->key.mode);
}

int		ft_get_cmd_interface(int press, int x, int y, t_env *e)
{
	if (e->key.mode == -1 || press == 2)
		return (-1);
	else if (e->key.mode == 2)
		return (ft_get_mm_cmd_interface(x, y, e));
	/*else if (e->key.mode = 5)
		return (ft_get_lm_cmd_interface(press, x, y, e));*/
	else if (e->key.mode == 6)
		return (ft_get_cm_cmd_interface(x, y, e));
	return (e->key.mode);
}

int		ft_exec_cmd(int mod, t_env *e)
{
	if (mod == 3)
		spawn_cam_menu(e);
	if (mod > 600 && mod <= 612)
	{
		ft_mod_cam_inc(e, mod);
		e->key.mode = 6;
	}
	if (e->key.mode == 6)
	{
		hide_interface_image(e);
		spawn_cam_menu(e);
		ft_print_pending_campos_modif(e);
		ft_print_pending_camdir_modif(e);
	}
	return (0);
}

int		ft_click(int press, int x, int y, t_env *e)
{
	ft_exec_cmd((ft_get_cmd_interface(press, x, y, e)), e);
	return (e->key.mode + x + y + press);
}
