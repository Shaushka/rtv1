/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_ui.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:11 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	ft_print_obj_ui(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (1. / 6.);
	y = INTER_H * (1. / 4.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x+");
	x = INTER_W * (1. / 6.);
	y = INTER_H * (3. / 4.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x-");
	x = INTER_W * (3. / 6.);
	y = INTER_H * (1. / 4.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y+");
	x = INTER_W * (3. / 6.);
	y = INTER_H * (3. / 4.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y-");
	x = INTER_W * (5. / 6.);
	y = INTER_H * (1. / 4.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z+");
	x = INTER_W * (5. / 6.);
	y = INTER_H * (3. / 4.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z-");
}

void	ft_print_cam_ui_2(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (3. / 24.);
	y = INTER_H * (9. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x+");
	x = INTER_W * (3. / 24.);
	y = INTER_H * (13. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x-");
	x = INTER_W * (11. / 24.);
	y = INTER_H * (9. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y+");
	x = INTER_W * (11. / 24.);
	y = INTER_H * (13. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y-");
	x = INTER_W * (19. / 24.);
	y = INTER_H * (9. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z+");
	x = INTER_W * (19. / 24.);
	y = INTER_H * (13. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z-");
}

void	ft_print_cam_ui(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (3. / 24.);
	y = INTER_H * (1. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x+");
	x = INTER_W * (3. / 24.);
	y = INTER_H * (5. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x-");
	x = INTER_W * (11. / 24.);
	y = INTER_H * (1. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y+");
	x = INTER_W * (11. / 24.);
	y = INTER_H * (5. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y-");
	x = INTER_W * (19. / 24.);
	y = INTER_H * (1. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z+");
	x = INTER_W * (19. / 24.);
	y = INTER_H * (5. / 16.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z-");
	ft_print_cam_ui_2(e);
}

void	ft_print_mm_ui(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (9. / 20.);
	y = INTER_H * (1. / 12.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "C");
	x = INTER_W * (9. / 20.);
	y = INTER_H * (5. / 12.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "L");
	x = INTER_W * (9. / 20.);
	y = INTER_H * (9. / 12.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "O");
}
