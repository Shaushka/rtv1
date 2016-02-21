/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:13:08 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

void			input_plane(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = PLANE;
	position(node);
	normal(node);
	color_choice(&node->color);
}

void			input_sphere(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	printf("INPUT_SPHERE	: Create_object : done\n");
	node->type = SPHERE;
	position(node);
	printf("INPUT_SPHERE	: Position : done\n");
	printf("Valeur : x = %f\n", node->pos.x);
	printf("Valeur : y = %f\n", node->pos.y);
	printf("Valeur : z = %f\n", node->pos.z);
	radius(node);
	printf("INPUT_SPHERE	: Radius : done\n");
	printf("Valeur : radius = %f\n", node->radius);
	color_choice(&node->color);
}

void			input_cylinder(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = CYLINDER;
	position(node);
	radius(node);
	height(node);
	color_choice(&node->color);
}

void			input_cone(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = CONE;
	position(node);
	radius(node);
	height(node);
	color_choice(&node->color);
}
