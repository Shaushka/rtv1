/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:13:11 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:26 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "libft.h"

static void		random_color(t_color *color)
{
	color->r = rand() % 255;
	color->g = rand() % 255;
	color->b = rand() % 255;
}

void			assign_color(t_color *color, char *str)
{
	int			i;

	i = 0;
	color->r = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	color->g = ft_atoi(cut_pos(str, i));
	while (ft_isdigit(str[i]))
		i++;
	i++;
	color->b = ft_atoi(cut_pos(str, i));
}

void			color(t_color *color)
{
	char		*tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la couleur :\n");
	ft_putstr("format : r/g/b (entre 0 et 255)");
	read(0, tmp, 200);
	while (!correct_input(tmp))
	{
		ft_bzero(tmp, 200);
		ft_putstr("entrez la couleur sous la forme r/g/b");
		read(0, tmp, 200);
	}
	if (check_values(tmp, 0, 255))
		assign_color(color, tmp);
	free(tmp);
}

static int		yes_or_no(char *str)
{
	if (ft_strequ(ft_strcapitalize(str), "OUI\n"))
	{
		ft_putstr("D'accord ! Vous choisissez les couleurs.\n");
		return (1);
	}
	if (ft_strequ(ft_strcapitalize(str), "NON\n"))
	{
		ft_putstr("Pas de probleme ! On a des couleurs toutes pretes !");
		return (0);
	}
	else
	{
		ft_putstr("Je n'ai pas compris. Du coup, j'ai choisi les couleurs !");
		return (0);
	}
}

void			color_choice(t_color *color)
{
	char		*tmp;
	char		*clean;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Voulez-vous choisir la couleur ?\n");
	ft_putstr("repondez oui ou non !");
	read(0, tmp, 200);
	clean = no_more_spaces(tmp);
	if (!correct_input(clean))
	{
		ft_bzero(tmp, 200);
		ft_putstr("ecrivez \"oui\" ou \"non\" : ");
		read(0, tmp, 200);
	}
	if (yes_or_no(clean))
		assign_color(color, clean);
	else
		random_color(color);
	free(tmp);
}
