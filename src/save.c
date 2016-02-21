/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgras <mgras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:43:59 by mgras             #+#    #+#             */
/*   Updated: 2016/02/21 19:56:52 by mgras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rtv1.h"
#include "libft.h"

static void			write_header(int fd, t_img img)
{
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(2, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd(0, fd);
	ft_putchar_fd((SCREEN_W & 0x00FF), fd);
	ft_putchar_fd((SCREEN_W & 0xFF00) / 256, fd);
	ft_putchar_fd((SCREEN_H & 0x00FF), fd);
	ft_putchar_fd((SCREEN_H & 0xFF00) / 256, fd);
	ft_putchar_fd(img.bpp, fd);
	ft_putchar_fd(0, fd);
}

int					write_img(int fd, t_env *e)
{
	t_img			img;
	size_t			i;
	int				ret;

	img = e->mlx_init.img;
	i = 0;
	while (i < SCREEN_H)
	{
		ret = write(fd,
				img.img_data + img.sizeline * (SCREEN_H - ++i),
				img.sizeline);
		if (ret < 0)
			return (1);
	}
	return (0);
}

int					save(t_env *e)
{
	int			fd;

	if ((fd = open("../export.tga", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) < 0)
	{
		perror("open: Canont open dest file for saving.");
		return (0);
	}
	write_header(fd, e->mlx_init.img);
	if (write_img(fd, e))
	{
		perror("write_img: error");
		return (0);
	}
	close(fd);
	return (0);
}
