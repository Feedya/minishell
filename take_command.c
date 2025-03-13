#include "head.h"

void	put_command_in_liste(char *str, int start, int end, t_line **head)
{
	t_line *node;
	t_line *prev;
	int	i;

	i = 0;
	node = create_node();
	node->valeur = malloc(sizeof(char) * (end - start + 1));
	if (node->valeur == NULL)
		exit (1); //FREE LA LISTE CHAINER
	while (start != end)
	{
		node->valeur[i] = str[start];
		start++;
		i++;
	}
	node->valeur[i] = '\0';
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
	node->quotes = NONE;
	node->type = TOKEN_COMMAND;
}

int	take_command(char *str, int index, t_line **head)
{
	int start;
	int	end;
	int	command;

	command = 0;
	while (str[index] == ' ')
		index++;
	start = index;
	while (str[index] != '\0')
	{
		if (str[index] != '\0' && str[index] != ' ' && command == 0)
		{
			while (str[index] != '\0' && str[index] != ' ')
				index++;
			command = 1;
		}
		while (str[index] == ' ')
			index++;
		if (str[index] == '-' && command == 1)
		{
			while (str[index] != '\0' && str[index] != ' ')
				index++;
		}
		if (str[index] != '-' && str[index] != ' ')
			break;
	}
	end = index;
	put_command_in_liste(str, start, end, head);
	return (index);
}
