
#include "rtv1.h"
/*
** REFRACTION = outside coeficient for refract mean outside resistance to light
*/
#define REFRACTION 1

float		ft_cost(float n, float cosi)
{
		return (1.0f - n * n * (1.0f - cosi * cosi));

}

t_color		refraction(t_object item, t_vector inter, t_env *e)
{
	t_vector	normal;
	t_vector	tmp;
	t_vector	test;
	t_color		color;
	float		coef;
	float		cosi;
	float		cost;

	if (g_depth < MAX_DEPTH)
	{
		coef = REFRACTION / item.refraction;
		inter = mult_vector(inter, -1);
		normal = calc_normal(e->cam.pos, item, inter);

			printf("%f, %f, %f --- %f, %f, %f\n",inter.x, inter.y, inter.z,  normal.x, normal.y, normal.z);
		if (dotpro_vector(inter, normal) > 0)
		{
			normal = mult_vector(normal, -1);

		//	coef = item.type != PLANE ? coef : item.refraction;
		}
			cosi = -dotpro_vector(normal, unit_vector(inter));
		if ((cost = ft_cost(coef, cosi)) > 0.0f)
		{
			g_depth++;
			test = mult_vector(unit_vector(inter), coef);
			test = add_vector(test, mult_vector(normal, coef * cosi - sqrt(cost)));
			color = (t_color){0, 0, 0};
			tmp = e->cam.pos;
			e->cam.pos = add_vector(inter, tmp);
			color = add_color(check_collision(e, unit_vector(test), e->cam.pos), color);
			e->cam.pos = tmp;
			g_depth--;
		}
	}
	return (color);
}
