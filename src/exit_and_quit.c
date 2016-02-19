#include "rtv1.h"
#include "libft.h"
#include "mlx.h"
#include "key_define.h"
#include <stdlib.h>

void			ft_exit(char *str, int n)
{
	ft_putendl_fd(str, 2);
	ft_wait_exit(n);
}

void			quit_and_free(t_env *e)
{
	mlx_destroy_image(e->key.interface.mlx, e->key.interface.img.img_ptr);
	mlx_destroy_image(e->mlx_init.mlx, e->mlx_init.img.img_ptr);
	mlx_destroy_window(e->mlx_init.mlx, e->mlx_init.win);
	ft_free_obj_lst(e->scene->l_obj);
	ft_free_light_lst(e->scene->light);
	ft_wait_exit(0);
}
