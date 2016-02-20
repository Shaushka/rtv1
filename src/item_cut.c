
#include "rtv1.h"

int		item_cut(t_vector pos, t_vector ray, t_object item)
{
	if (norm_vector(item.cut) > 0)

	dotpro_vector(pos, ray);
//	{
//		ray = unit_vector(add_vector(pos, ray));
//		return (dotpro_vector(ray, unit_vector(item.cut)) < 0 ? 1 : 0);
//	}
	return (0);
}
