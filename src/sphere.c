#include "rtv1.h"
#include <math.h>

t_object		set_sphere(t_vector pos, float radius)
{
	t_object	sphere;

	sphere.type = SPHERE;
	sphere.pos = pos;
	sphere.radius = radius;
	sphere.height = 0;
	sphere.shine = 0;
	sphere.reflect = 0;
	sphere.checkered = 0;
	sphere.refraction = 0;
	sphere.cut = (t_vector){ 0, 0 , 0};
	return (sphere);
}

float			inter_sphere(t_vector cam_pos, t_vector ray, t_object obj)
{
	float		a;
	float		b;
	float		c;
	float		t;
	t_vector	tmp;

	tmp = sub_vector(cam_pos, obj.pos);
	a = sq_vector(ray);
	b = 2 * dotpro_vector(tmp, ray);
	c = dotpro_vector(tmp, tmp) - (obj.radius * obj.radius);
	t = b * b - 4 * a * c;
	if (t < 0.0f)
		return (0);
	c = (-b + sqrt(t)) / (2 * a);
	t = (-b - sqrt(t)) / (2 * a);
	c = item_cut(cam_pos, mult_vector(ray, t), obj) ? -1: c;
	t = item_cut(cam_pos, mult_vector(ray, t), obj) ? -1: t;
	if (t < 0.f || (c < t))
		return (c);
	else
		return(t);
	return (a);
}

t_vector		normal_sphere(t_vector cam, t_object obj, t_vector ray)
{
	t_vector	tmp;

	tmp = sub_vector(add_vector(cam, ray), obj.pos);
	tmp = unit_vector(tmp);
	if (dotpro_vector(unit_vector(ray), unit_vector(tmp)) > 0)
	{
		printf("%f, %f, %f\n", tmp.x, tmp.y, tmp.z);
		return (mult_vector(tmp, -1));
	}
	return (tmp);
}
