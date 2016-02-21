/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_and_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:15:32 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		read_scene(int fd, t_parse *parse, t_env *e)
{
	int		ret;
	char	*line;
	char	*swp;
	char	*get;

	get = ft_strdup("");
	if ((line = (char *)malloc(sizeof(char) * BUF_SIZE + 1)) == NULL)
		error_in_parse("Error: malloc line");
	ret = 0;
	while ((ret = read(fd, line, BUF_SIZE)) > 0)
	{
		line[ret] = 0;
		swp = get ? ft_strjoin(get, line) : ft_strdup(line);
		ft_strdel(&get);
		get = ft_strdup(swp);
		ft_strdel(&swp);
		ft_strclr(line);
	}
	ft_strdel(&line);
	line = NULL;
	get_instr(get, parse, e);
	ft_strdel(&get);
}

void			open_file(char *file, t_parse *parse, t_env *e)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: open");
		ft_wait_exit(1);
	}
	parse->name = ft_strdup(file);
	read_scene(fd, parse, e);
	if (close(fd) == -1)
	{
		perror("Error: close");
		ft_wait_exit(1);
	}
}

void			get_scene(t_env *e, char *file)
{
	t_parse		*parse;

	(void)e;
	if ((parse = (t_parse *)malloc(sizeof(t_parse))) == NULL)
	{
		perror("Error: malloc t_parse");
		ft_wait_exit(1);
	}
	if ((parse->obj = (t_object *)malloc(sizeof(t_object))) == NULL)
	{
		perror("Error: malloc t_obj");
		ft_wait_exit(1);
	}
	if ((parse->light = (t_light *)malloc(sizeof(t_light))) == NULL)
	{
		perror("Error: malloc t_light");
		ft_wait_exit(1);
	}
	parse->obj->next = NULL;
	parse->light->next = NULL;
	open_file(file, parse, e);
	ft_free_parse(parse);
	e->scene->l_obj = parse->obj;
	e->scene->light = parse->light;
	e->lights = parse->light;
}
