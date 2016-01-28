/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verification.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguillon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:03:15 by mguillon          #+#    #+#             */
/*   Updated: 2016/01/28 14:38:26 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char 	*ft_str_nospace(char *str)
{
	char *clean;
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

char *separators(char *str)//remplace les /// en trop par des espaces
{
	char *clean;
	int i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '/')
		{
			i++;
			while(str[i] == '/')
			{
				str[i] = ' ';
				j++;
			}
		}
		else
			i++;
	}
}


int		isvector(char *str)
{
	//je supprime les espaces
	char *clean;
	clean = ft_str_nospace(str);
	free(str);
	//j'ai une nouvelle string propre sans espaces. 
	//je verifie si ce sont bien des chiffres et des nombres.
	if (is_slashes_and_digits)
}

int		is_slashes_and_digits(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '/')
			return (0);
		else
			i++;
	}
	return (1);
}
