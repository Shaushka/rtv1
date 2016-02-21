/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:38 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	ft_keyring_cammod_reset_pos(t_env *e, int render)
{
	e->cam.pos = (t_vector){0., 0., 0.};
	if (render)
	{
		ft_render(e);
		mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
				e->mlx_init.img.img_ptr, 0, 0);
	}
}

void	ft_keyring_cammod_reset_dir(t_env *e, int render)
{
	e->cam.dir = unit_vector((t_vector){1., 0., 0.});
	if (render)
	{
		ft_render(e);
		mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
				e->mlx_init.img.img_ptr, 0, 0);
	}
}

void	ft_keyring_lightmod_apply(t_env *e)
{
	e->key.selected_light = 0;
	e->key.mode = -1;
	ft_render(e);
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
}

void	ft_keyring_objmod_apply(t_env *e)
{
	e->key.selected_obj = 0;
	e->key.mode = -1;
	ft_render(e);
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
}

void	ft_keyring_cammod_apply(t_env *e)
{
	e->cam.pos.x += e->key.cam_inc.pos.x;
	e->cam.pos.y += e->key.cam_inc.pos.y;
	e->cam.pos.z += e->key.cam_inc.pos.z;
	e->cam.dir.x += e->key.cam_inc.dir.x;
	e->cam.dir.y += e->key.cam_inc.dir.y;
	e->cam.dir.z += e->key.cam_inc.dir.z;
	e->cam.dir = unit_vector(e->cam.dir);
	set_cam_to_zero(&(e->key.cam_inc));
	ft_render(e);
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
}
