#include "head.h"


int	take_pipe(int index, t_line **head)
{
	t_line *new_node;
	t_line *prev;

	new_node = create_node();
	new_node->valeur = malloc(sizeof(char) * 2);
	if (new_node->valeur == NULL)
		exit (1); //FREE TOUTE LA LISTE
	new_node->valeur[0] = '|';
	new_node->valeur[1] = '\0';
	new_node->quotes = NONE;
	new_node->type = TOKEN_PIPE;
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = new_node;
	new_node->prev = prev;
	new_node->next = NULL;
	return (index + 1);
}

int	take_redirect_out(int index, t_line **head)
{
	t_line *node;
	t_line *prev;

	node = create_node();
	node->valeur = malloc(sizeof(char) * (2));
	if (node->valeur == NULL)
		exit (1);//FREE LISTE
	node->valeur[0] = '>';
	node->valeur[1] = '\0';
	node->quotes = NONE;
	node->type = TOKEN_REDIRECT_OUT;
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
	return (index + 1);
}

int	take_redirect_in(t_line **head)
{
	t_line *prev;
	t_line *node;

	node = create_node();
	node->valeur = malloc(sizeof(char) * 2);
	if (node->valeur == NULL)
		exit (1);//FREE LISTE CHAINEE
	node->valeur[0] = '<';
	node->valeur[1] = '\0';
	node->quotes = NONE;
	node->type = TOKEN_REDIRECT_IN;
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
	return (1);
}

int	take_append(t_line **head)
{
	t_line *node;
	t_line *prev;

	node = create_node();
	node->valeur = malloc(sizeof(char) * (3));
	if (node->valeur == NULL)
		exit (1); //FREE LISTE CHAINER
	node->valeur[0] = '>';
	node->valeur[1] = '>';
	node->valeur[2] = '\0';
	node->quotes = NONE;
	node->type = TOKEN_APPEND;
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
	return (2);
}

int	take_heredoc(t_line **head)
{
	t_line *node;
	t_line *prev;

	node = create_node();
	node->valeur = malloc(sizeof(char) * 3);
	if (node->valeur == NULL) //FREE LISTE CHAINER
		exit (1);
	node->valeur[0] = '<';
	node->valeur[1] = '<';
	node->valeur[2] = '\0';
	node->quotes = NONE;
	node->type = TOKEN_HEREDOC;
	prev = *head;
	while (prev->next != NULL)
		prev = prev->next;
	prev->next = node;
	node->prev = prev;
	return (2);
}
