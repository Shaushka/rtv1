/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 18:26:58 by chuang            #+#    #+#             */
/*   Updated: 2016/02/19 16:43:48 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
	print_result(parse);
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
}
/*
void        start(int argc, const char **argv)
{
	t_env    *e;
	int        x;
	int        y;

	e = (t_env*)ft_strnew(sizeof(t_env));
	if (e == NULL)
	{
		ft_putendl_fd("Malloc error", 2);
		ft_wait_exit(-1);
	}
	if (initialise_stuct(e, argc, argv) == NULL)
		ft_wait_exit(-1);
	x = e->v_map.win_x;
	y = e->v_map.win_y;
	if ((e->win = mlx_new_window(e->mlx, x, y, "RTv1")) == NULL)
		ft_wait_exit(-1);
	ft_restart(e);
}
*/
static void	sign_hand(int signnum)
{
	(void)signnum;
	wait4(0, 0, WNOHANG, 0);
}

void    ft_wait_exit(int n)
{
	wait(NULL);
	exit(n);
}

static void	start(int argc, char **argv)
{
	t_env	e;

	init_scene(&e);
	init_lights(&e);
	if (argc > 1)
		get_scene(&e, argv[argc - 1]);
	init_and_draw(&e, argv[0]);
	ft_wait_exit(0);
}

static void	gestion_multi(int argc, char **argv)
{
	pid_t        pid;

	signal(SIGCHLD, sign_hand);//est appele quand le child die
	pid = 1;
	if (argc > 2 && (pid = fork()) < 0)
		exit(0);
	if (pid == 0)
	{//le fils part en recursive
		gestion_multi(argc - 1, argv);
		ft_wait_exit(0);
	}
	else
	{//le pere va direct s'occuper de son argc
		start(argc, argv);
		ft_wait_exit(0);
	}
}

int            main(int argc, char **argv)
{
	if (argc < 2)//error
		//ft_putendl_fd("Map error : I need a map", 2);
		start(argc, argv);
	else if (argc == 2)//pas besoin de fork
		start(argc, argv);
	else//go for the fork
		gestion_multi(argc, argv);
	return (0);
}
