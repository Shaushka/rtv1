/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:16:28 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:17:27 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		sign_hand(int signnum)
{
	(void)signnum;
	wait4(0, 0, WNOHANG, 0);
}

void			ft_wait_exit(int n)
{
	wait(NULL);
	exit(n);
}

static void		start(int argc, char **argv)
{
	t_env	e;

	init_scene(&e);
	if (argc > 1)
		get_scene(&e, argv[argc - 1]);
	init_and_draw(&e, argv[0]);
	ft_wait_exit(0);
}

static void		gestion_multi(int argc, char **argv)
{
	pid_t		pid;

	signal(SIGCHLD, sign_hand);
	pid = 1;
	if (argc > 2 && (pid = fork()) < 0)
		exit(0);
	if (pid == 0)
	{
		gestion_multi(argc - 1, argv);
		ft_wait_exit(0);
	}
	else
	{
		start(argc, argv);
		ft_wait_exit(0);
	}
}

int				main(int argc, char **argv)
{
	if (argc < 2)
		start(argc, argv);
	else if (argc == 2)
		start(argc, argv);
	else
		gestion_multi(argc, argv);
	return (0);
}
