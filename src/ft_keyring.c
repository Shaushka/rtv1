/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 16:55:14 by mgras             #+#    #+#             */
/*   Updated: 2016/02/17 14:36:45 by mgras            ###   ########.fr       */
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
		return (ft_get_lm_cmd_interface(press, x, y, e));
	else if (e->key.mode = 6)
		return (ft_get_cm_cmd_interface(press, x, y, e));*/
	return (e->key.mode);
}

int		ft_exec_cmd(int mod, t_env *e)
{
	if (mod == 3)
		spawn_cam_menu(e);
	return (0);
}

int		ft_click(int press, int x, int y, t_env *e)
{
	ft_exec_cmd((ft_get_cmd_interface(press, x, y, e)), e);
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

void	set_cam_to_zero(t_cam *cam)
{
	t_vector	v;

	cam->pos = set_vector(v, 0, 0, 0);
	cam->dir = set_vector(v, 0, 0, 0);
	cam->h = set_vector(v, 0, 0, 0);
	cam->d = set_vector(v, 0, 0, 0);
}

void	init_keyring(t_env *e)
{
	e->key.mouse_x = 0;
	e->key.mouse_y = 0;
	e->key.interface.mlx = e->mlx_init.mlx;
	e->key.interface.win = e->mlx_init.win;
	e->key.selected_light = 0;
	e->key.selected_obj = 0;
	e->key.mode = -1;
	set_cam_to_zero(&(e->key.cam_inc));
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

void	spawn_cam_menu(t_env *e)
{
	t_color		c;
	t_vector	v;

	set_color_from_rgb(&c, 255, 100, 100);
	ft_print_square(c,
		set_vector(v, 0. , 0., 0.),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 4.), 0), e);//cam pos x +
	set_color_from_rgb(&c, 255, 20, 20);
	ft_print_square(c,
		set_vector(v, 0, (double)INTER_H * (1. / 4.), 0),
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (2. / 4.), 0), e);//cam pos x -
	set_color_from_rgb(&c, 100, 155, 100);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), 0., 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (1. / 4.), 0), e);
	set_color_from_rgb(&c, 20, 155, 20);
	ft_print_square(c,
		set_vector(v, INTER_W * (1. / 3.), (double)INTER_H * (1. / 4.), 0.),
		set_vector(v, INTER_W * (2. / 3.), (double)INTER_H * (2. / 4.), 0), e);
	e->key.mode = 2;
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win, e->key.interface.img.img_ptr, 0, 0);
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
