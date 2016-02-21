/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:50 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:53:21 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		key_press_hook_3(int keycode, t_env *e)
{
	if (keycode == KEY_ENTER && e->key.mode == 6)
		ft_keyring_cammod_apply(e);
	else if (keycode == KEY_ENTER && e->key.mode == 5)
		ft_keyring_lightmod_apply(e);
	else if (keycode == KEY_ENTER && e->key.mode == 8)
		ft_keyring_objmod_apply(e);
	else if (keycode == KEY_TAB && e->key.mode == 5)
	{
		ft_get_next_light(e);
		ft_print_pending_light(e, 5);
	}
	else if (keycode == KEY_TAB && e->key.mode == 8)
	{
		ft_get_next_obj(e);
		ft_print_pending_obj(e, 8);
	}
	else if (e->key.mode == 6 && keycode == KEY_R)
	{
		ft_keyring_cammod_reset_pos(e, 0);
		ft_keyring_cammod_reset_dir(e, 1);
	}
	return (keycode);
}

void	ft_set_sepia_filter(t_env *e)
{
	t_light	*swp;

	swp = e->lights;
	if (!swp)
		return ;
	while (swp)
	{
		swp->color = (t_color){155, 75, 25};
		swp = swp->next;
	}
	e->ambiant = 0.0;
}

int		key_press_hook_2(int keycode, t_env *e)
{
	key_press_hook_3(keycode, e);
	ft_new_obj_hook(keycode, e);
	if (keycode == KEY_L)
		ft_set_sepia_filter(e);
	if (keycode == KEY_J)
		spawn_soft_light(e);
	if (keycode == KEY_H)
		ft_nape_generator_init(e);
	if (keycode == KEY_K)
		save(e);
	if (keycode == KEY_F)
		ft_jellybeans_generator(e);
	if (keycode == KEY_G)
		ft_generatore(0, 0, 0, e);
	return (0);
}

int		key_press_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		ft_wait_exit(0);
	if (keycode == KEY_COMMAND && e->key.mode != 2)
	{
		hide_interface_image(e);
		spaw_main_menu(e);
	}
	else if (keycode == KEY_COMMAND && e->key.mode == 2)
		hide_interface_image(e);
	key_press_hook_2(keycode, e);
	if (keycode == KEY_Z)
	{
		e->ambiant += 0.1;
		ft_render(e);
		mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
				e->mlx_init.img.img_ptr, 0, 0);
	}
	else if (keycode == KEY_A)
	{
		e->ambiant -= 0.1;
		ft_render(e);
		mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
				e->mlx_init.img.img_ptr, 0, 0);
	}
	return (0);
}
