char		*cut_pos(char *str, int i)
{
	char *tmp;
	while(str[i] != '/')
	{
		i++;
		j++;
	}
	tmp = malloc(sizeof(char) * (j + 1));
	i = 0;
	while(str[i] != '/')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\n'
		return (tmp);
}

void		assign_pos(t_object *node, char *str)
{
	node->pos.x = ft_atoi(cut_pos(str, i));
	while(ft_isdigit(str[i]))
		i++;
	i++;
	node->pos.y = ft_atoi(cut_pos(str, i));
	while(ft_isdigit(str[i]))
		i++;
	i++;
	node->pos.z = ft_atoi(cut_pos(str, i));
}

void		position(t_object *node)
{
	char *tmp;

	tmp = ft_memalloc(sizeof(char) * 200);
	ft_bzero(tmp, 200);
	ft_putstr("Definition de la position :");
	ft_putstr("Format : x/y/z (entre 1 et 100) : ");
	read(0, tmp, 200);
	while (!correct_input(tmp))
	{
		ft_bzero(tmp, 200);
		ft_putstr("Entrez la position sous la forme x/y/z : ");
		read(0, tmp, 200);
	}//gerer si trop loin pour etre visible ??
	assign_pos(node, tmp);
	free(tmp);
}
