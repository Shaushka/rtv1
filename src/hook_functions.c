/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:53 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int				spawn_soft_light(t_env *e)
{
	t_light		*swp;
	int			link_nb;

	swp = e->lights;
	link_nb = ft_get_new_bundle_nb_l(e);
	while (swp && swp->next)
		swp = swp->next;
	if (!swp)
		return (0);
	swp->next = ft_new_light_hook((t_vector){2., 0., 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){2., 0.01, 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){1., -0.01, 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){2.01, 0., 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){2., 0., 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){1.99, 0., 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){1., 0., 2.}, link_nb);
	swp = swp->next;
	swp->next = ft_new_light_hook((t_vector){1., 0., 2.01}, link_nb);
	return (0);
}

t_light			*ft_new_light_hook(t_vector pos, int link_nb)
{
	t_light		*n;

	n = create_light_p();
	n->pos.x = pos.x;
	n->pos.y = pos.y;
	n->pos.z = pos.z;
	n->color = (t_color){255, 255, 255};
	n->intensity = 0.1;
	n->bundle = link_nb;
	return (n);
}

int				expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
	return (0);
}

void			ft_new_obj_hook(int keycode, t_env *e)
{
	t_object	*n;
	t_object	*swp;

	swp = e->scene->l_obj;
	n = NULL;
	if (keycode >= KEY_1 && keycode <= KEY_4 && swp)
	{
		n = create_object_p();
		while (swp && swp->next)
			swp = swp->next;
		n->type = keycode == KEY_1 ? SPHERE : n->type;
		n->type = keycode == KEY_2 ? PLANE : n->type;
		n->type = keycode == KEY_3 ? CYLINDER : n->type;
		n->type = keycode == KEY_4 ? CONE : n->type;
		n->pos = (t_vector){e->cam.pos.x + 2, e->cam.pos.y, e->cam.pos.z};
		n->pos.z = keycode == KEY_3 ? -500 : n->pos.z;
		n->dir = unit_vector((t_vector){0, 0, 1});
		n->normal = (t_vector){1, 0, 0};
		n->radius = 0.2;
		n->height = -1.;
		n->shine = 1;
		n->reflect = 0.2;
		n->refraction = 0.;
		swp->next = n;
	}
}

void			ft_generatore(int x, int y, int z, t_env *e)
{
	t_object	*swp;
	double		teta;
	int			link_nb;

	swp = e->scene->l_obj;
	teta = 0.;
	link_nb = ft_get_new_bundle_nb(e);
	while (teta < 2 * PI && swp)
	{
		x = x + 0;
		ft_new_obj_hook(KEY_1, e);
		while (swp && swp->next)
			swp = swp->next;
		swp->bundle = link_nb;
		swp->pos.x = e->cam.pos.x + 2;
		swp->pos.z = z + cos(teta) - (cos(teta) / 1.5);
		swp->pos.y = y + sin(teta) - (sin(teta) / 1.5);
		swp->color = (t_color){0, 0, 0};
		teta += 0.02;
	}
}
