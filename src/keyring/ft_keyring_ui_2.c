/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_ui_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:09 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	ft_print_light_ui_4(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (2. / 8.);
	y = INTER_H * ((2. + 35.) / 42.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "i+");
	x = INTER_W * (6. / 8.);
	y = INTER_H * ((2. + 35.) / 42.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "i-");
}

void	ft_print_light_ui_3(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (3. / 18.);
	y = INTER_H * ((0. + 12.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "r+");
	x = INTER_W * (3. / 18.);
	y = INTER_H * ((3. + 12.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "r-");
	x = INTER_W * (9. / 18.);
	y = INTER_H * ((0. + 12.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "g+");
	x = INTER_W * (9. / 18.);
	y = INTER_H * ((3. + 12.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "g-");
	x = INTER_W * (15. / 18.);
	y = INTER_H * ((0. + 12.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "b+");
	x = INTER_W * (15. / 18.);
	y = INTER_H * ((3. + 12.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "b-");
	ft_print_light_ui_4(e);
}

void	ft_print_light_ui_2(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (3. / 18.);
	y = INTER_H * ((0. + 6.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x+");
	x = INTER_W * (3. / 18.);
	y = INTER_H * ((3. + 6.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x-");
	x = INTER_W * (9. / 18.);
	y = INTER_H * ((0. + 6.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y+");
	x = INTER_W * (9. / 18.);
	y = INTER_H * ((3. + 6.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y-");
	x = INTER_W * (15. / 18.);
	y = INTER_H * ((0. + 6.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z+");
	x = INTER_W * (15. / 18.);
	y = INTER_H * ((3. + 6.) / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z-");
	ft_print_light_ui_3(e);
}

void	ft_print_light_ui(t_env *e)
{
	int		x;
	int		y;

	x = INTER_W * (3. / 18.);
	y = INTER_H * (0. / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x+");
	x = INTER_W * (3. / 18.);
	y = INTER_H * (3. / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "x-");
	x = INTER_W * (9. / 18.);
	y = INTER_H * (0. / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y+");
	x = INTER_W * (9. / 18.);
	y = INTER_H * (3. / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "y-");
	x = INTER_W * (15. / 18.);
	y = INTER_H * (0. / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z+");
	x = INTER_W * (15. / 18.);
	y = INTER_H * (3. / 21.);
	mlx_string_put(e->mlx_init.mlx, e->mlx_init.win, x, y, 0x0, "z-");
	ft_print_light_ui_2(e);
}
