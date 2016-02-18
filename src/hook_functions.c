/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:59:19 by agadiffe          #+#    #+#             */
/*   Updated: 2016/02/18 10:57:59 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
	return (0);
}

int		key_press_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_COMMAND && e->key.mode != 2)
	{
		hide_interface_image(e);
		spaw_main_menu(e);
	}
	else if (keycode == KEY_COMMAND && e->key.mode == 2)
		hide_interface_image(e);
	else if (keycode == KEY_ENTER && e->key.mode == 6)
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
	else if (keycode == KEY_Z)
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
