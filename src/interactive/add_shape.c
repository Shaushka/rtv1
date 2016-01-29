#include <unistd.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

void			input_plane(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	position(node);
	normal(node);
	constant(node);
}

void			input_sphere(t_env *e)
{
	t_object	*node;

	node = create_object(e);
	position(node);
	diameter(node);
	//color(node);
	//colorscheme?
}

//creer une fonction set_object qui permet d'avoir en 1l les infos
