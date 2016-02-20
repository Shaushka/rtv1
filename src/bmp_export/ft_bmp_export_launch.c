#include "rtv1.h"
#include "mlx.h"
#include "key_define.h"
#include <signal.h>

char	*ft_get_legal_name(void)
{
	char	*swp;
	char	*tmp;
	int		try;

	try = 0;
	tmp = ft_itoa(try);
	swp = ft_strjoin(D_XP_PATH, tmp);
	ft_strdel(&tmp);
	if (access(swp, F_OK) == -1)
		return (swp);
	while (access(swp, F_OK) != -1)
	{
		ft_strdel(&swp);
		tmp = ft_itoa(try++);
		swp = ft_strjoin(D_XP_PATH, tmp);
		ft_strdel(&tmp);
	}
	return (swp);
}

char	*ft_make_bmp(t_env *e)
{
	char	*bmp_ex;
	int		x;

	x = 0;
	bmp_ex = (char*)malloc(sizeof(char) * (SCREEN_W * SCREEN_H));
	bmp_ex[x++] = 'B';
	bmp_ex[x++] = 'A';
	bmp_ex[x++] = (char)(SCREEN_W * SCREEN_H);
	while (x < 14)
		bmp_ex[x++] = 0;
	bmp_ex[x++] = 40;
	while (x < SCREEN_W * SCREEN_H)
		bmp_ex[x ++] = 1;
	bmp_ex[x ++] = '\0';
	(void)e;
	return (bmp_ex);
}

void	export_screen_to_bmp(t_env *e)
{
	char	*file_name;

	file_name = ft_get_legal_name();
	ft_mkfile(file_name);
	ft_export_bmp(file_name, ft_make_bmp(e));
	ft_strdel(&file_name);
}

void	ft_export_bmp(char *file_name, char *bmp)
{
	int		fd;

	ft_putnbr(fd = open(file_name, O_WRONLY));
	ft_putstr_fd(bmp, fd);
	ft_strdel(&bmp);
	close(fd);
}

void	ft_mkfile(char *filename)
{
	pid_t	child;
	int		sys;
	char	**argv;

	child = fork();
	argv = NULL;
	if (child == 0)
	{
		argv = (char**)malloc(sizeof(char*) * 3);
		argv[2] = NULL;
		argv[1] = ft_strdup(filename);
		argv[0] = (char*)malloc(sizeof(char) * ft_strlen("touch") + 1);
		ft_strcpy(argv[0], "touch");
		execve("/usr/bin/touch", argv, NULL);
		ft_strdel(&(argv[0]));
		ft_strdel(&(argv[1]));
		kill(getpid(), SIGKILL);
	}
	wait(&sys);
}
