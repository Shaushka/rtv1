
#include "rtv1.h"
/*
 ** REFRACTION = outside coeficient for refract mean outside resistance to light
 */
#define REFRACTION 1.0f


float		ft_cost(float eta, float cosi)
{
	return (1.0f - eta * eta * (1.0f - cosi * cosi));
}
/*
   t_color		refraction(t_object item, t_vector inter, t_env *e)
   {
   t_vector	normal;
   t_vector	tmp;
   t_vector	refray;
   t_color		color;
   float		eta;
   float		cosi;
   float		cost;
   float			inside;

   color = (t_color){0, 0, 0};
   if (g_depth < MAX_DEPTH)
   {
   eta = item.refraction;
   normal = calc_normal(e->cam.pos, item, inter);
   inside = dotpro_vector(unit_vector(inter), normal);

   printf("%f\n", inside);
   if (inside > 0)
   {
   printf("noob\n");
   normal = mult_vector(normal, -1);
//			eta = item.type == PLANE ? REFRACTION : REFRACTION / item.refraction;
eta = REFRACTION / item.refraction;
}
cosi = -dotpro_vector(normal, unit_vector(inter));
if ((cost = ft_cost(eta, cosi)) > 0.0f)
{
g_depth++;
//			refray = mult_vector(unit_vector(inter), eta);
//			refray = add_vector(refray, mult_vector(normal, (eta * cosi - sqrtf(cost))));
refray = add_vector(mult_vector(unit_vector(inter), eta), mult_vector(normal, (eta * cosi - sqrtf(cost))));
refray = unit_vector(refray);

//printf("%f, %f, %f\n", refray.x, refray.y, refray.z);
tmp = e->cam.pos;
e->cam.pos = add_vector(add_vector(inter, e->cam.pos), mult_vector(refray, 1e-4));
color = add_color(check_collision(e, unit_vector(refray), e->cam.pos), color);
e->cam.pos = tmp;
g_depth--;
}
}
return (color);
}*/

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


	color = (t_color){0,0,0};
	if (g_depth < MAX_DEPTH)
	{
		norm = calc_normal(e->cam.pos, item, inter);
		inside = dotpro_vector(unit_vector(inter), norm);
		eta = inside ? item.refraction / REFRACTION : REFRACTION / item.refraction ;
		if (inside > 0.0f)
		{
			printf ("inside\n");
			norm = mult_vector(norm, -1);
		}
		cosi = -dotpro_vector(norm, inter);
		(k = 1.0f - eta * eta * (1.0f - cosi * cosi));
		{
			g_depth++;
			refray = add_vector(mult_vector(unit_vector(inter), eta), mult_vector(norm, (eta * cosi - sqrtf(k))));
			refray = unit_vector(refray);
			tmp = e->cam.pos;
			pos = add_vector(add_vector(inter, e->cam.pos), mult_vector(refray, 1e-4));
			e->cam.pos = pos;
			color = add_color(check_collision(e, refray, e->cam.pos), color);
			e->cam.pos = tmp;
			g_depth--;
		}
	}
	return (color);
}
