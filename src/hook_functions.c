#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
			e->mlx_init.img.img_ptr, 0, 0);
	return (0);
}

void	ft_new_obj_hook(int keycode, t_env *e)
{
	t_object	*n;
	t_object	*swp;

	swp = e->scene->l_obj;
	n = NULL;
	if (keycode >= KEY_1 && keycode <= KEY_4)
	{
		n = create_object_p();
		while (swp && swp->next)
			swp = swp->next;
		n->type = keycode == KEY_1 ? SPHERE : n->type;
		n->type = keycode == KEY_2 ? PLANE : n->type;
		n->type = keycode == KEY_3 ? CYLINDER : n->type;
		n->type = keycode == KEY_4 ? CONE : n->type;
		n->color = (t_color){255, 255, 255};
		n->pos = (t_vector){e->cam.pos.x + 2, e->cam.pos.y, e->cam.pos.z};
		n->dir = unit_vector((t_vector){0, 0, 1});
		n->normal = (t_vector){1, 0, 0};
		n->radius = 0.2;
		n->height = -1.;
		n->shine = 1;
		n->reflect = 0.2;
		n->refraction = 0.;
		swp->next = n;
	}
}

void	ft_generatore(int x, int y, int z, t_env *e)
{
	t_object	*swp;
	double		teta;
	int			link_nb;

	swp = e->scene->l_obj;
	teta = 0.;
	link_nb = ft_get_new_bundle_nb(e);
	while (teta < 2 * PI)
	{
		x = x + 0;
		ft_new_obj_hook(KEY_1, e);
		while (swp && swp->next)
			swp = swp->next;
		swp->bundle = link_nb;
		swp->pos.x = e->cam.pos.x + 2;
		swp->pos.z = z + cos(teta) - (cos(teta) / 1.5);
		swp->pos.y = y + sin(teta) - (sin(teta) / 1.5);
		teta += 0.09;
	}
}

int		key_press_hook_2(int keycode, t_env *e)
{
	if (keycode == KEY_ENTER && e->key.mode == 6)
		ft_keyring_cammod_apply(e);
	else if (keycode == KEY_ENTER && e->key.mode == 5)
		ft_keyring_lightmod_apply(e);
	else if (keycode == KEY_ENTER && e->key.mode == 8)
		ft_keyring_objmod_apply(e);
	else if (keycode == KEY_TAB && e->key.mode == 5)
	{
		ft_get_next_light(e);
		ft_print_pending_light(e, 5);
	}
	else if (keycode == KEY_TAB && e->key.mode == 8)
	{
		ft_get_next_obj(e);
		ft_print_pending_obj(e, 8);
	}
	else if (e->key.mode == 6 && keycode == KEY_R)
	{
		ft_keyring_cammod_reset_pos(e, 0);
		ft_keyring_cammod_reset_dir(e, 1);
	}
	ft_new_obj_hook(keycode, e);
	if (keycode == KEY_G)
		ft_generatore(0, 0, 0, e);
	return (0);
}

int		key_press_hook(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
		ft_wait_exit(0);
	if (keycode == KEY_COMMAND && e->key.mode != 2)
	{
		hide_interface_image(e);
		spaw_main_menu(e);
	}
	else if (keycode == KEY_COMMAND && e->key.mode == 2)
		hide_interface_image(e);
	key_press_hook_2(keycode, e);
	if (keycode == KEY_Z)
	{
		e->ambiant += 0.1;
		ft_render(e);
		mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
				e->mlx_init.img.img_ptr, 0, 0);
	}
	else if (keycode == KEY_A)
	{
		e->ambiant -= 0.1;
		ft_render(e);
		mlx_put_image_to_window(e->mlx_init.mlx, e->mlx_init.win,
				e->mlx_init.img.img_ptr, 0, 0);
	}
	if (keycode == KEY_M)
		export_screen_to_bmp(e);
	return (0);
}
