
#include "rtv1.h"

int		item_cut(t_vector pos, t_vector ray, t_object item)
{
	if (norm_vector(item.cut) > 0)
	{
		pos = unit_vector(sub_vector(add_vector(ray, pos), item.pos));
		return (dotpro_vector(pos, unit_vector(item.cut)) < 0 ? 1 : 0);
	}
	return (0);
}
