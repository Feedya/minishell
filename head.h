#ifndef HEAD_H
#define HEAD_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum token_type //le type de chaque charactere qu on regarde
{
  TOKEN_SINGLE_QUOTES, //' '
  TOKEN_DOUBLE_QUOTES, // ""
  TOKEN_PIPE, // |
  TOKEN_REDIRECT_IN, // <
  TOKEN_REDIRECT_OUT, // >
  TOKEN_APPEND, // >>
  TOKEN_HEREDOC, // <<
	TOKEN_COMMAND
} token_type;

typedef enum quotes // pour savoir si le charactere qu on regarde si il est dans des double single ou pas de quotes
{
  DOUBLE_QUOTES,
  SINGLE_QUOTES,
  NONE
} quotes;

typedef struct t_line
{
  struct t_line *next;
	struct t_line *prev;
  char	*valeur;
  token_type type;
	quotes		quotes;
} t_line;

/*
typedef struct t_all
{
  char *line;
  char path;
  char env;
} t_all;
*/


int	take_first_command(char *str, t_line **head);
t_line	*create_node(void);
t_line	**create_head(void);

//REDIRICITON
int	take_heredoc(t_line **head);
int	take_append(t_line **head);
int	take_redirect_in(t_line **head);
int	take_redirect_out(int index, t_line **head);
int	take_pipe(int index, t_line **head);

//TAKE COMMAND
int	take_command(char *str, int index, t_line **head);

#endif