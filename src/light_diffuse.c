#include "rtv1.h"

float	diffuse_light(t_light light, t_object item, t_vector inter, t_env *e)
{
	float		coef;
	float		attenuation;
	t_vector	light_ray;
	t_vector	normal;

	light_ray = sub_vector(light.pos, add_vector(inter, e->cam.pos));
	normal = calc_normal(e->cam.pos, item, inter);
	coef = dotpro_vector(unit_vector((light_ray)), unit_vector(normal));
	attenuation = ((100.f - norm_vector(light_ray)) / 100.f);
	if (attenuation < 0)
		attenuation = 0;
	coef *= (light.intensity - 0.1 * (float)(norm_vector(inter) / 10));
	if (coef > 1)
		coef = 1;
	if (coef < 0)
		coef = 0;
	return (coef);
}
