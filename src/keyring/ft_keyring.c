/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:16 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

/*
**	mode -1 = all is hidden, will go to mode 1 when respawned whith keybinding
**	mode 0 = all must be hidden
**	mode 1 = must spaw main menu
**	mode 2 = main menu is up waiting for command
**	mode 3 = must spawn camera menu
**	mode 4 = must spaw light menu
**	mode 5 = light menu is up and waiting for command
**			**mode 500 + 01 = light.pos.x++;
**			**mode 500 + 02 = light.pos.x--;
**			**mode 500 + 03 = light.pos.y++;
**			**mode 500 + 04 = light.pos.y--;
**			**mode 500 + 05 = light.pos.z++;
**			**mode 500 + 06 = light.pos.z--;
**			**mode 500 + 07 = light.dir.x++;
**			**mode 500 + 08 = light.dir.x--;
**			**mode 500 + 09 = light.dir.y++;
**			**mode 500 + 10 = light.dir.y--;
**			**mode 500 + 11 = light.dir.z++;
**			**mode 500 + 12 = light.dir.z--;
**			**mode 500 + 13 = light.color.r++;
**			**mode 500 + 14 = light.color.r--;
**			**mode 500 + 15 = light.color.g++;
**			**mode 500 + 16 = light.color.g--;
**			**mode 500 + 17 = light.color.b++;
**			**mode 500 + 18 = light.color.b--;
**			**mode 500 + 19 = light.intensity++;
**			**mode 500 + 20 = light.intensity--;
** mode 6 = camera menu is up and waiting for command
**			**mode 600 + 01 = cam.pos.x++;
**			**mode 600 + 02 = cam.pos.x--;
**			**mode 600 + 03 = cam.pos.y++;
**			**mode 600 + 04 = cam.pos.y--;
**			**mode 600 + 05 = cam.pos.z++;
**			**mode 600 + 06 = cam.pos.z--;
**			**mode 600 + 07 = cam.dir.x++;
**			**mode 600 + 08 = cam.dir.x--;
**			**mode 600 + 09 = cam.dir.y++;
**			**mode 600 + 10 = cam.dir.y--;
**			**mode 600 + 11 = cam.dir.z++;
**			**mode 600 + 12 = cam.dir.z--;
** mode 7 = must spaw obj menu
** mode 8 = obj menu is up and waiting for command
**			**mode 800 + 01 = obj.pos.x++;
**			**mode 800 + 02 = obj.pos.x--;
**			**mode 800 + 03 = obj.pos.y++;
**			**mode 800 + 04 = obj.pos.y--;
**			**mode 800 + 05 = obj.pos.z++;
**			**mode 800 + 06 = obj.pos.z--;
*/

int		ft_get_cmd_interface(int press, int x, int y, t_env *e)
{
	if (e->key.mode == -1 || press == 2)
		return (-1);
	else if (e->key.mode == 2)
		return (ft_get_mm_cmd_interface(x, y, e));
	else if (e->key.mode == 5)
		return (ft_get_lm_cmd_interface(x, y, e));
	else if (e->key.mode == 6)
		return (ft_get_cm_cmd_interface(x, y, e));
	else if (e->key.mode == 8)
		return (ft_get_om_cmd_interface(x, y, e));
	return (e->key.mode);
}

void	ft_print_pending_light(t_env *e, int mod)
{
	ft_mod_light_inc(e, mod);
	hide_interface_image(e);
	spawn_light_menu(e);
	ft_print_pending_lightpos_modif(ft_get_light_at_nb(
									e->key.selected_light, e->lights), e);
	ft_print_pending_lightdir_modif(ft_get_light_at_nb(
									e->key.selected_light, e->lights), e);
	ft_print_pending_lightcol_modif(ft_get_light_at_nb(
									e->key.selected_light, e->lights), e);
	ft_print_pending_lightint_modif(ft_get_light_at_nb(
									e->key.selected_light, e->lights), e);
	ft_print_selected_light(e);
	ft_print_light_ui(e);
	e->key.mode = 5;
}

void	ft_print_pending_obj(t_env *e, int mod)
{
	ft_mod_obj_inc(e, mod);
	e->key.mode = 8;
	hide_interface_image(e);
	spawn_obj_menu(e);
	ft_print_pending_objpos_modif(ft_get_obj_at_nb(e->key.selected_obj,
									e->scene->l_obj), e);
	ft_print_selected_obj(e);
	ft_print_obj_ui(e);
}

int		ft_exec_cmd(int mod, t_env *e)
{
	if (mod == 3)
		spawn_cam_menu(e);
	if (e->key.mode == 4 && e->scene->light)
		spawn_light_menu(e);
	if (e->key.mode == 7 && e->scene->l_obj)
		spawn_obj_menu(e);
	if (mod > 600 && mod <= 612)
	{
		ft_mod_cam_inc(e, mod);
		e->key.mode = 6;
		hide_interface_image(e);
		spawn_cam_menu(e);
		ft_print_pending_campos_modif(e);
		ft_print_pending_camdir_modif(e);
		ft_print_cam_ui(e);
	}
	if (mod > 500 && mod <= 520 && e->scene->light)
		ft_print_pending_light(e, mod);
	if (mod > 800 && mod <= 806 && e->scene->l_obj)
		ft_print_pending_obj(e, mod);
	return (0);
}

int		ft_click(int press, int x, int y, t_env *e)
{
	ft_exec_cmd((ft_get_cmd_interface(press, x, y, e)), e);
	return (e->key.mode + x + y + press);
}
