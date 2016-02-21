/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:43 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"

t_img	ft_get_texture(char *xpm_file_name, int xpm_w, int xpm_h, t_env *e)
{
	t_img	img;

	if ((access(xpm_file_name, F_OK)) != -1)
	{
		img.img_ptr = mlx_xpm_file_to_image(e->mlx_init.mlx,
				xpm_file_name, &xpm_w, &xpm_h);
	}
	else if ((access(XPM_DEFAULT, F_OK)) != -1)
	{
		img.img_ptr = mlx_xpm_file_to_image(e->mlx_init.mlx,
				XPM_DEFAULT, &xpm_w, &xpm_h);
	}
	else
	{
		img.img_data = NULL;
		img.img_ptr = NULL;
		return (img);
	}
	img.img_data = mlx_get_data_addr(img.img_ptr, &(img.bpp), &(img.sizeline),
									&(img.endian));
	img.opp = img.bpp / 8;
	return (img);
}
