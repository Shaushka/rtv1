/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:26:58 by chuang            #+#    #+#             */
/*   Updated: 2016/02/19 18:04:36 by mguillon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rtv1.h"

void			ft_wait_exit(int n)
{
	exit(n);
}

static void		read_scene(int fd, t_parse *parse, t_env *e)
{
	int		ret;
	char	*line;
	char	*get;

	get = ft_strdup("");
	if ((line = (char *)malloc(sizeof(char) * BUF_SIZE + 1)) == NULL)
		error_in_parse("Error: malloc line");
	ret = 0;
	while ((ret = read(fd, line, BUF_SIZE)) > 0)
	{
		line[ret] = 0;
		get = ft_strjoin(get, line);
		ft_strclr(line);
	}
	free(line);
	line = NULL;
	get_instr(get, parse, e);
}

void			open_file(char *file, t_parse *parse, t_env *e)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: open");
		exit(1);
	}
	parse->name = ft_strdup(file);
	read_scene(fd, parse, e);
	if (close(fd) == -1)
	{
		perror("Error: close");
		exit(1);
	}
	print_result(parse);
}

void			get_scene(t_env *e, char *file)
{
	t_parse		*parse;

	(void)e;
	if ((parse = (t_parse *)malloc(sizeof(t_parse))) == NULL)
	{
		perror("Error: malloc t_parse");
		exit(1);
	}
	if ((parse->obj = (t_object *)malloc(sizeof(t_object))) == NULL)
	{
		perror("Error: malloc t_obj");
		exit(1);
	}
	parse->obj->next = NULL;
	open_file(file, parse, e);
	e->scene->l_obj = parse->obj;
	e->scene->light = parse->light;
}

int				main(int argc, char **argv)
{
	t_env	e;

	init_scene(&e);
	//init_lights(&e);
	argv = (char **)argv;
//	if (argc != 1)
//		ft_exit("usage: ./rtv1", 1);
	if (argc == 2)
	{
		if (ft_strequ(argv[1], "interactive"))
			create_scene(&e);
		else
			get_scene(&e, argv[1]);
	}
	else
		set_list_obj(&e);
	init_and_draw(&e, argv[0]);
	return (0);
}
