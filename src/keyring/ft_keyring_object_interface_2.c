#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		ft_get_om_cmd_interface(int x, int y, t_env *e)
{
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > 0 && y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 1);
	if (x >= 0 && x <= INTER_W * (1. / 3.) && y > INTER_H * (1. / 2.) &&
		y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 2);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) && y > 0 &&
		y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 3);
	if (x >= INTER_W * (1. / 3.) && x <= INTER_W * (2. / 3.) &&
		y > INTER_H * (1. / 2.) && y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 4);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > 0 && y <= INTER_H * (1. / 2.))
		return (e->key.mode = 800 + 5);
	if (x >= INTER_W * (2. / 3.) && x <= INTER_W &&
		y > INTER_H * (1. / 2.) && y <= INTER_H * (2. / 2.))
		return (e->key.mode = 800 + 6);
	return (e->key.mode);
}
