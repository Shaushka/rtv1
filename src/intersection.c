#include "rtv1.h"

float		intersection(t_object *tmp, t_vector ray, t_vector pos)
{
	if (tmp->type == SPHERE)
		return (inter_sphere(pos, ray, *tmp));
	else if (tmp->type == PLANE)
		return (inter_plane(pos, ray, *tmp));
	else if (tmp->type == CONE)
		return (inter_cone(pos, ray, *tmp));
	else if (tmp->type == CYLINDER)
		return (inter_cylinder(pos, ray, *tmp));
	return (0.f);
}
