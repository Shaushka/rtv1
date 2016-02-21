/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyring_nape_generator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:14:57 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

void	ft_nape_generator_init(t_env *e)
{
	int		link_nb;

	link_nb = ft_get_new_bundle_nb(e);
	ft_quater_nappe((t_vector){0., (double)(PI / 2), 0}, e,
								(t_vector){0, 0, 0}, link_nb);
	ft_quater_nappe((t_vector){(double)(PI), (double)(1.5 * PI), 0}, e,
								(t_vector){0, 0.675, 0}, link_nb);
	ft_quater_nappe((t_vector){0., (double)(PI / 2), 0}, e,
								(t_vector){0.25, 0, 0}, link_nb);
	ft_quater_nappe((t_vector){(double)(PI), (double)(1.5 * PI), 0}, e,
								(t_vector){0.25, 0.675, 0}, link_nb);
	ft_quater_nappe((t_vector){0., (double)(PI / 2), 0}, e,
								(t_vector){0.5, 0, 0}, link_nb);
	ft_quater_nappe((t_vector){(double)(PI), (double)(1.5 * PI), 0}, e,
								(t_vector){0.5, 0.675, 0}, link_nb);
	ft_quater_nappe((t_vector){0., (double)(PI / 2), 0}, e,
								(t_vector){0.75, 0, 0}, link_nb);
	ft_quater_nappe((t_vector){(double)(PI), (double)(1.5 * PI), 0}, e,
								(t_vector){0.75, 0.675, 0}, link_nb);
}

void	ft_jellybeans_generator(t_env *e)
{
	int		link_nb;

	link_nb = ft_get_new_bundle_nb(e);
	ft_quater_nappe((t_vector){0., (double)(PI / 2), 0}, e,
								(t_vector){-1, 1, 0}, link_nb);
	link_nb = ft_get_new_bundle_nb(e);
	ft_quater_nappe((t_vector){(double)(PI / 2), (double)PI, 0}, e,
								(t_vector){1, -1, 0}, link_nb);
}

void	ft_quater_nappe(t_vector t, t_env *e, t_vector s, int link_nb)
{
	t_object	*swp;

	swp = e->scene->l_obj;
	while (t.x < t.y && swp)
	{
		ft_new_obj_hook(KEY_1, e);
		while (swp && swp->next)
			swp = swp->next;
		swp->bundle = link_nb;
		swp->pos.x = s.x + e->cam.pos.x + 2;
		swp->pos.z = s.z + cos(t.x) - (cos(t.x) / 1.5);
		swp->pos.y = s.y + sin(t.x) - (sin(t.x) / 1.5);
		swp->color = (t_color){0, 0, 0};
		swp->radius = 0.2;
		t.x += 0.02;
	}
}
