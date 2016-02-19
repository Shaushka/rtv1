#include "rtv1.h"

static int			check_shit(char *str)
{
	int				i;
	int				test;

	i = 0;
	test = 0;
	while (str[i])
	{
		if (str[i] == '/')
			test = 1;
		if (test == 1 && str[i] == '>')
			test = 2;
		i++;
	}
	if (test == 2)
		return (1);
	else
		return (0);
}

static int			get_the_mark(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			return (i);
		i++;
	}
	return (i);
}

static int			set_node(t_node **nodes, int pos, char **tab)
{
	t_node			*new_node;
	char			*swp;
	int				t;
	static t_fam	n = NONE;

	swp = ft_strtrim(tab[pos]);
	if (check_shit(tab[pos]) == 1 || ft_strncmp(swp, "objet>", 6) == 0)
	{
		n = OBJECT;
		return (pos + 1);
	}
	ft_strdel(&swp);
	swp = ft_strtrim(tab[pos]);
	if (check_shit(tab[pos]) == 1 || ft_strncmp(swp, "light>", 6) == 0)
	{
		n = LIGHT;
		return (pos + 1);
	}
	ft_strdel(&swp);
	if ((new_node = (t_node *)malloc(sizeof(t_node))) == NULL)
		error_in_parse("Error: malloc new t_node");
	else
	{
		t = get_the_mark(tab[pos]);
		new_node->family = n;
		new_node->type = ft_strsub(tab[pos], 0, t);
		new_node->value = ft_strsub(tab[pos], t + 1, ft_strlen(tab[pos]));
		new_node->next = NULL;
		(*nodes)->next = new_node;
		(*nodes) = (*nodes)->next;
	}
	return (pos + 2);
}

static void			recup_nodes(t_node *nodes, t_parse *parse, t_env *e)
{
	t_object	*tmp_object;
	t_light		*tmp_light;

	(void)e;
	tmp_object = NULL;
	tmp_light = NULL;
	if (nodes && (nodes = nodes->next) != NULL)
	{
		while (nodes)
		{
			if (nodes->family == OBJECT)
			{
				if (ft_strcmp(nodes->type, "type") == 0)
				{
					if (!tmp_object)
					{
						tmp_object = create_object_p();
						parse->obj = tmp_object;
					}
					else
					{
						tmp_object->next = create_object_p();
						tmp_object = tmp_object->next;
					}
					set_object_type(nodes->value, tmp_object);
				}
				else
					set_object_param(nodes->type, nodes->value, tmp_object);
			}
			else if (nodes->family == LIGHT)
			{
				if (ft_strcmp(nodes->type, "lighttype") == 0)
				{
					if (!tmp_light)
					{
						tmp_light = create_light_p();
						parse->light = tmp_light;
					}
					else
					{
						tmp_light->next = create_light_p();
						tmp_light = tmp_light->next;
					}
					set_light_type(nodes->value, tmp_light);
				}
				else
					set_light_param(nodes->type, nodes->value, tmp_light);
			}
			nodes = nodes->next;
		}
	}
}

