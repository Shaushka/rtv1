
#include "rtv1.h"

t_color		refraction(t_object item, t_vector inter, t_env *e)
{
	

	if (g_depth < MAX_DEPTH)
	{
		calc_normal(e->cam.pos, item, inter);

	}
}
