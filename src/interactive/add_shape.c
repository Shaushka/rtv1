/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:09:16 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/27 15:07:33 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

void			input_plane(t_env *e)
{
	t_object	*node;
	node = create_object(e);
	position(node);
	normal(node);
	constant(node);
}

void			input_sphere(t_env *e)
{
	t_object	*node;
	node = create_object(e);
	position(node);
	diameter(node);
}
