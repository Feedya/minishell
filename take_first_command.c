#include "head.h"

void	put_first_node(char *str, int start, int end, t_line **head)
{
	t_line *new_node;
	int	taille;
	int	i;

	i = 0;
	taille = end - start;
	new_node = create_node();
	new_node->valeur = malloc(sizeof(char) * (taille + 1));
	if (new_node->valeur == NULL)
		exit (1); //FREE TOUTE LA LISTE
	while (start != end)
	{
		new_node->valeur[i] = str[start];
		i++;
		start++;
	}
	new_node->valeur[i] = '\0';
	new_node->quotes = NONE;
	new_node->type = TOKEN_COMMAND;
	if (*head == NULL)
		*head = new_node;
}

int	take_first_command(char *str, t_line **head)
{
	int	i;
	int	first_command;
	int start;
	int	end;

	first_command = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != ' ' && first_command == 0)
		{
			while (str[i] != '\0' && str[i] != ' ' && first_command == 0)
				i++;
			first_command = 1;
		}
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] == '-' && str[i] != ' ')
		{
			if (str[i + 1] == ' ')
				break;
			while (str[i] != '\0' && str[i] != ' ' && first_command == 1)
				i++;
		}
		if ((str[i] == '\0') || (str[i] != ' ' && str[i] != '-'))
			break;
	}
	end = i;
	put_first_node(str, start, end, head);
	return (end);
}
