/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:10:14 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/12 18:36:54 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include "../includes/rtv1.h"
#include "../libft/libft.h"
// valeur de retour ?

/*int		ft_isword(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		//printf("%s%c\n", "evaluation du caractere : ", str[i]);
		if (str[i] != '\n' && !ft_isalpha(str[i]))
			return (0);
		else
			i++;
	}
	return (1);
}*/

static int		isshape(char *str)
{
	if (ft_strequ(str, "sphere\n") || ft_strequ(str, "Sphere\n"))
		return (1);
	if (ft_strequ(str, "cylindre\n") || ft_strequ(str, "Cylindre\n"))
		return (2);
	if (ft_strequ(str, "cone\n") || ft_strequ(str, "Cone\n"))
		return (3);
	if (ft_strequ(str, "plan\n") || ft_strequ(str, "Plan\n"))
		return (4);
	else
		return (0);
}

static void	create_scene()//je passerai l'env en param aussi
{
	ft_putstr("Quel type d'element voulez-vous ajouter a la scene ? : ");
	char *tmp;

	tmp	= ft_memalloc(sizeof(char) * 200);
	read(0, tmp, 200);
	while (/*!ft_isword(tmp) || */!isshape(tmp))
	{	
		ft_putstr("Choisissez sphere, cone, cylindre ou plan : ");
		ft_bzero(tmp, 200);
		read(0, tmp, 200);
		if (!isshape(tmp))
			ft_putstr("Vous m'avez encore demande l'impossible ! ");
	}
	if (isshape(tmp))
		ft_putstr("Ah, bah voila un utilisateur cooperatif !\n");
	if (isshape(tmp) == 1)//SPHERE
		ft_sphere(e)	
		
		//add a la liste correspondante
	}
	else
	{
		ft_putstr("Pas une forme autorisee, ca !");
	}
}

int		main(int argc, char **argv)
{
	argv = (char **)argv; 
	if (argc > 1)
		return (0);
	else
	{
		create_scene();
		return (1);
	}
}
