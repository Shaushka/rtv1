/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:55:14 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 12:35:00 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"

int		ft_click(int press, int x, int y, t_env *e)
{
	return (e->key.mode + press + x + y);
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

void	del_interface_image(t_env *e)
{
	mlx_destroy_image(e->key.interface.mlx, e->key.interface.img.img_ptr);
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
	e->key.mode = 0;
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

	set_color_from_rgb(&c, 190, 30, 30);
	ft_print_square(c,
				set_vector(v, 0 + INTER_W / 100., 0 + INTER_H / 100., 0),
				set_vector(v, 0 + INTER_W / 90., 0 + INTER_H / 90., 0), e);
	set_color_from_rgb(&c, 30, 190, 30);
	ft_print_square(c,
				set_vector(v, 0 + INTER_W / 80., 0 + INTER_H / 80., 0),
				set_vector(v, 0 + INTER_W / 70., 0 + INTER_H / 70., 0), e);
	set_color_from_rgb(&c, 30, 30, 190);
	ft_print_square(c,
				set_vector(v, 0 + INTER_W / 80., 0 + INTER_H / 80., 0),
				set_vector(v, 0 + INTER_W / 70., 0 + INTER_H / 70., 0), e);
}
