#include "head.h"

// "" '' < > << >> | $
// premier arguments toujoury 1 commande
// ce qui suit c est sois des flags sois des arguments ou les deux
// on peut avoir qu une seule commande 
// premier arguments toujours commande
// donc premier while devra aller tant qu on a pas pris
// toute la commande plus le flag si y a 

t_line	**create_head(void)
{
	t_line **head;

	head = malloc(sizeof(t_line *));
	if (head == NULL)
		return (NULL);
	return (head);
}

t_line	*create_node(void)
{
	t_line *new_node;

	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->valeur = NULL;
	new_node->quotes = NONE;
	new_node->type = TOKEN_DOUBLE_QUOTES;
	return (new_node);
}

t_line	**parsing(char *str)
{
	int	index;
	t_line **head;
	int	command;

	command = 0;
	if ((head = create_head()) == NULL)
		exit (1);
	index = take_first_command(str, head);
	while (str[index] != '\0')
	{
		if (str[index] == '|')
		{
			index = take_pipe(index, head);
			command = 1;
		}
		else if (command == 1 && str[index] != ' ' && str[index] != '\0'
		&& str[index] != '<' && str[index] != '>' && str[index] != '|')
		{
			index = take_command(str, index, head);
			command = 0;
		}
		else if (str[index] == '>' && str[index + 1] != '>')
			index = take_redirect_out(index, head);
		else if (str[index] == '<' && str[index + 1] != '<')
			index += take_redirect_in(head);
		else if (str[index] == '>' && str[index + 1] == '>')
			index += take_append(head);
		else if (str[index] == '<' && str[index + 1] == '<')
			index += take_heredoc(head);
		else
			index++;
	}
	return (head);
}

int	main(void)
{
	t_line *node;
	t_line **head;
	char *str = "hello --flags  <<>>-hihi>  >| world -flag | koko -pipi";
	head = parsing(str);
	node = *head;
	while (node != NULL)
	{
		printf("%s\n", node->valeur);
		node = node->next;
	}
	return (0);
}