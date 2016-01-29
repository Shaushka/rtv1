#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

void			input_plane(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = PLANE;
	position(node);
	normal(node);
	constant(node);
}

void			input_sphere(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = SPHERE;
	position(node);
	radius(node);
	//color(node);
	//colorscheme?
}
void			input_cylinder(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = CYLINDER;
	position(node);
	radius(node);
	height(node);
	//color(node);
	//colorscheme?
}


void			input_cone(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	node->type = CONE;
	position(node);
	radius(node);
	height(node);
	//color(node);
	//colorscheme?
}


//creer une fonction set_object qui permet d'avoir en 1l les infos
