#include <unistd.h>
#include <stdio.h>
#include "../includes/rtv1.h"
#include "../libft/includes/libft.h"

static int		isshape(char *str)
{//strcapitalize pour verif toutes les orthographes possibles
	if (ft_strequ(str, "sphere\n") || ft_strequ(str, "Sphere\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (1);
	}
	if (ft_strequ(str, "cylinder\n") || ft_strequ(str, "Cylinder\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (2);
	}
	if (ft_strequ(str, "cone\n") || ft_strequ(str, "Cone\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (3);
	}
	if (ft_strequ(str, "plan\n") || ft_strequ(str, "Plan\n"))
	{
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
		return (4);
	}
	else
		return (0);
}

void			create_scene(t_env *e)
{
	int			x;
	char		*tmp;

	ft_putstr("Quel type d'element voulez-vous ajouter a la scene ? : ");
	tmp = ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while (!isshape(tmp))
	{
		ft_putstr("Choisissez sphere, cone, cylindre ou plan : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
	}
	x = isshape(tmp);
	if (x == 1)//SPHERE
		input_sphere(e);
	else if (x == 2)//CYLINDER
		input_cylinder(e);
	else if (x == 3)//CONE
		input_cone(e);
	else if (x == 4)//PLANE
		input_plane(e);
	free(tmp);
}
