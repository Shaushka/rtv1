
#include "rtv1.h"

#define REFRACTION 1.0f

/*
 ** REFRACTION = outside coeficient for refract mean outside resistance to light
 */

float		ft_cost(float eta, float cosi)
{
	return (1.0f - eta * eta * (1.0f - cosi * cosi));
}

t_color		refraction(t_object item, t_vector inter, t_env *e)
{
	t_vector		refray;
	t_vector		pos;
	t_vector		norm;
	t_vector		tmp;
	t_color			color;
	float			inside;
	float			k;
	float			eta;
	float			cosi;

	color = (t_color){0, 0, 0};
	if (g_depth < MAX_DEPTH)
	{
		norm = calc_normal(e->cam.pos, item, inter);
		inside = dotpro_vector(unit_vector(inter), norm);
		eta = inside ? item.refraction / REFRACTION : REFRACTION / item.refraction;
		if (inside > 0.0f)
			norm = mult_vector(norm, -1);
		cosi = -dotpro_vector(norm, inter);
		(k = 1.0f - eta * eta * (1.0f - cosi * cosi));
		{
			g_depth++;
			refray = add_vector(mult_vector(unit_vector(inter), eta), mult_vector(norm, (eta * cosi - sqrtf(k))));
			refray = unit_vector(refray);
			tmp = e->cam.pos;
			e->cam.pos = add_vector(add_vector(inter, e->cam.pos), mult_vector(refray, 1e-4));
			color = add_color(check_collision(e, refray, e->cam.pos), color);
			e->cam.pos = tmp;
			g_depth--;
		}
	}
	return (color);
}
