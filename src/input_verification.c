/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:03:15 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 13:12:38 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char 	*ft_str_nospace(char *str)
{
	char *clean
	int len = ft_strlen(char *str);
	int i = 0;
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
		{
			j++;
			i++;
		}
		else
			i++;
	}
	len -= j;
	clean = malloc(sizeof(char) * (len + 1));
	i = 0;
	j = 0;
	while(str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			clean[j] = str[i];
			i++;
			j++;
		}
	}
	free(str);
	return (clean);
}

int		isvector(char *str)
{//on a une str sans espace et ne contenant que des chiffres et des /
	
}

int		isclean(char *str)
{
	char *clean;

	clean = ft_str_nospace(str);
	free(str);
	int i = 0;
	while (clean[i] != '\0')//est ce que ce sont bien des chiffres et des '/'
	{
		if (!ft_isdigit(clean[i]) && clean[i] != '/')
			return (0);
		else
			i++;
	}
	// si oui :
	if (isvector(clean))
		return (1);
	else
		return (0);
}
