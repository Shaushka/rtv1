#include "rtv1.h"

t_color		shall_i_reflect(t_object item, t_vector inter, t_env *e)
{
	t_color	tmp_color;

	if (item.reflect > 0)
	{
		tmp_color = reflection(item, inter, e);
		return (add_color(item.color, tmp_color));
	}
	else
		return (item.color);
}

t_color		shall_i_refract(t_object item, t_vector inter, t_env *e)
{
	if (item.refraction > 0)
		return (add_color(item.color, refraction(item, inter, e)));
	else
		return (item.color);
}
