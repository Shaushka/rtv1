/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 12:10:14 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/12 16:55:00 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include "../includes/rtv1.h"
#include "../libft/libft.h"
// valeur de retour ?

int		ft_isword(char *str)
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
}

int		isshape(char *str)
{
	if (ft_strequ(str, "sphere\n"))
		return (1);
	if (ft_strequ(str, "cylindre\n"))
		return (2);
	if (ft_strequ(str, "cone\n"))
		return (3);
	if (ft_strequ(str, "plan\n"))
		return (4);
	else
		return (0);
}

void	create_scene()//je passerai l'env en param aussi
{
	ft_putstr("Quel type d'element voulez-vous ajouter a la scene ? : ");
	char *tmp;
   
	tmp	= ft_memalloc(sizeof(char) * 11);
	read(0, tmp, 11);
	while (!ft_isword(tmp))
	{	
		ft_putstr("Choisissez sphere, cone, cylindre ou plan : ");
		ft_bzero(tmp, 11);
		read(0, tmp, 10);
		ft_putstr(tmp);
	}
	if (isshape(tmp))
	{
		ft_putstr("Oh la jolie sphere !\n");
	}		//add a la liste correspondante
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
