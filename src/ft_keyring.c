/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:55:14 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 13:23:14 by mgras            ###   ########.fr       */
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
*/

int		ft_click(int press, int x, int y, t_env *e)
{
	return (e->key.mode + x + y + press);
}

void	new_interface_image(t_env *e)
{
	if (!(e->key.interface.img.img_ptr = mlx_new_image(
													e->key.interface.mlx,
													SCREEN_W / 5,
													SCREEN_H / 5)))
		ft_exit("Can't create image", 1);
	if (!(e->key.interface.img.img_data = mlx_get_data_addr(
												e->key.interface.img.img_ptr,
												&e->key.interface.img.bpp,
												&e->key.interface.img.sizeline,
												&e->key.interface.img.endian)))
		ft_exit("Can't get image adress", 1);
	e->key.interface.img.opp = e->key.interface.img.bpp / 8;
}

void	hide_interface_image(t_env *e)
{
	mlx_put_image_to_window(e->mlx_init.mlx,
							e->mlx_init.win,
							e->mlx_init.img.img_ptr,
							0,
							0);
	e->key.mode = -1;
}

void	init_keyring(t_env *e)
{
	e->key.mouse_x = 0;
	e->key.mouse_y = 0;
	e->key.visible = 0;
	e->key.interface.mlx = e->mlx_init.mlx;
	e->key.interface.win = e->mlx_init.win;
	e->key.selected_light = 0;
	e->key.selected_obj = 0;
	e->key.mode = -1;
	new_interface_image(e);
}

int		ft_mouse_move(int x, int y, t_env *e)
{
	ft_putnbr(e->key.mouse_x = x);
	ft_putchar('\n');
	ft_putnbr(e->key.mouse_y = y);
	ft_putchar('\n');
	return (0);
}

void	spaw_main_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	set_color_from_rgb(&c, 190, 90, 90);
	ft_print_square(c,
		set_vector(v, 0. , 0., 0.),
		set_vector(v, INTER_W, (double)INTER_H * (1./3.), 0), e);
	set_color_from_rgb(&c, 90, 190, 90);
	ft_print_square(c,
		set_vector(v, 0. , (double)INTER_H * (1./3.), 0.),
		set_vector(v, INTER_W, (double)INTER_H * (2./3.), 0), e);
	set_color_from_rgb(&c, 90, 90, 190);
	ft_print_square(c,
		set_vector(v, 0. , (double)INTER_H * (2./3.), 0.),
		set_vector(v, INTER_W, (double)INTER_H * (3./3.), 0), e);
	e->key.mode = 2;
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win, e->key.interface.img.img_ptr, 0, 0);
}
