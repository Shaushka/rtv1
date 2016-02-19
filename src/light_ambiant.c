#include "rtv1.h"

t_color			ambiant_light(t_object item)
{
	item.color = mult_color(item.color, AMBIANT);
	return (item.color);
}
