#include "parser.h"

static void	read_scene(int fd, t_parse *parse)
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
//	ft_putstr(get);
	get_instr(get, parse);
}

void		open_file(char *file, t_parse *parse)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror("Error: open");
		exit(1);
	}
	parse->name = ft_strdup(file);
	read_scene(fd, parse);
	if (close(fd) == -1)
	{
		perror("Error: close");
		exit(1);
	}
	print_result(parse);
}

void	usage(char *argv)
{
	ft_putstr("usage: ");
	ft_putstr(argv);
	ft_putendl(" scene");
	exit(1);
}

int main(int argc, char **argv)
{
	t_parse		*parse;

	if (argc != 2)
		usage(argv[0]);
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
	open_file(argv[1], parse);
	return(0);
}
