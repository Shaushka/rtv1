#include "parser.h"

/**
** en gros l'idée c'est d'avoir des reperes dans notre fichier scene qui
** correspondent aux niveaux des infos
** ici :
** {} = niveau 0 = nom de ce qu'on traite
** () = niveau 1 = nom de ce qu'on donne à son sujet
** [] = niveau 2 = valeurs données
**/

static void	include_node(t_node **nodes, int pos, char c)
{
	t_node	*new_node;

	if ((new_node = (t_node *)malloc(sizeof(t_node))) == NULL)
		error_in_parse("Error: malloc new t_node");
	new_node->beg = pos;
	new_node->type = c;
	new_node->next = NULL;
	(*nodes)->next = new_node;
	(*nodes) = (*nodes)->next;
}

static void	clean_nodes(t_node **nodes)
{
	while (*nodes)
	{
		free(*nodes);
		*nodes = (*nodes)->next;
	}
}

static void	recup_nodes(t_node *nodes, char *get, t_parse *parse)
{
	int	len;
	char	*value;
	char	*data;
	t_object	*tmp;

	tmp = NULL;
	len = 0;
	if (nodes && (nodes = nodes->next) != NULL)
	{
		while (nodes)
		{
			len = get_size(get, nodes->beg + 1, '}');
			if (nodes->type == '}')
			{
				if (!tmp)
				{
					tmp = create_object();
					parse->obj = tmp;
				}
				else
				{
					tmp->next = create_object();
					tmp = tmp->next;
				}
				value = recup_name(nodes, get, '\n');
				set_object_type(value, tmp);
			}
			else if (nodes->type == ')' || nodes->type == ']')
			{
				value = recup_name(nodes, get, '\n');
				data = ft_strtrim(ft_strsub(get, nodes->beg + 1, len));
				set_object_param(value, data, tmp);
			}
/*			else if (nodes->type == ']')
			{
				value = recup_name(nodes, get, '\n');
				data = ft_strtrim(ft_strsub(get, nodes->beg + 1, len));
				set_object_param(value, data, tmp);
			}*/
			nodes = nodes->next;
		}
	}

}

void	get_instr(char *get, t_parse *parse)
{
	int	pos;
	int	i;
	t_node	*tmp;

	if ((parse->nodes = (t_node *)malloc(sizeof(t_node))) == NULL)
		error_in_parse("Error: malloc t_node");
	tmp = parse->nodes;
	pos = 0;
	i = 0;
	while (get[i])
	{
		if (get[i] && get[i] == '{')
			include_node(&parse->nodes, i, '}');
		else if (get[i] && get[i] == '(')
			include_node(&parse->nodes, i, ')');
		else if (get[i] && get[i] == '[')
			include_node(&parse->nodes, i, ']');
		i++;
	}
	// print_nodes(tmp);
	recup_nodes(tmp, get, parse);
	clean_nodes(&tmp);
}
