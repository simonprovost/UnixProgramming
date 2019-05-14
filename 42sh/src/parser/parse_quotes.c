/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** parse_quotes
*/

#include "42sh.h"

char *get_next_arg(char ***cmd, char *arg, int *size, char *quote_char);

int check_quotes(char *cmd, int i)
{
	int offset = 0;
	int save = i;
	char c = 0;

	if (cmd[i] != '"' && cmd[i] != '\'')
		return (i);
	c = cmd[i];
	for (i--; i >= 0; i--) {
		offset++;
		if (cmd[i] == c)
			return (save - offset);
	}
	return (0);
}

int check_bad_quotes(char *cmd)
{
	char quote = 0;

	for (int i = 0; cmd && cmd[i]; i++) {
		if (!quote && (cmd[i] == '"' || cmd[i] == '\''))
			quote = cmd[i];
		else if (quote && cmd[i] == quote)
			quote = 0;
	}
	if (quote) {
		printf("Unmatched %c.\n", quote);
		return (1);
	}
	return (0);
}

void check_recursivity_quote(char ***cmd, char **arg,
						int *size, char *quote_char)
{
	if ((*cmd)[0] && *quote_char) {
		(*arg) = realloc(*arg, *size);
		(*arg)[*size - 1] = ' ';
		*size += 1;
		(*arg) = get_next_arg(cmd, *arg, size, quote_char);
	}
}

char *get_next_arg(char ***cmd, char *arg, int *size, char *quote_char)
{
	if (!*cmd || !(*cmd)[0])
		return (NULL);
	for (int i = 0; (*cmd[0]) && (*cmd[0])[i]; i++) {
		if (((*cmd[0])[i] == '"' || (*cmd[0])[i] == '\'')
		&& (!*quote_char
		|| (*quote_char && (*cmd[0])[i] == *quote_char))) {
			*quote_char = (*quote_char == 0 ? (*cmd[0])[i] : 0);
			continue;
		}
		arg = realloc(arg, *size);
		arg[*size - 1] = (*cmd[0])[i];
		*size += 1;
	}
	*cmd += 1;
	check_recursivity_quote(cmd, &arg, size, quote_char);
	arg = realloc(arg, *size);
	arg[*size - 1] = 0;
	return (arg);
}

char **parse_quotes(char **cmd)
{
	int i = 1;
	int size = 1;
	char quote_char = 0;
	char *arg = NULL;
	char **new = NULL;

	if (!cmd)
		return (NULL);
	while ((arg = get_next_arg(&cmd, NULL, &i, &quote_char))) {
		new = realloc(new, sizeof(char *) * size);
		new[size - 1] = strdup(arg);
		free(arg);
		arg = NULL;
		size += 1;
		i = 1;
		quote_char = 0;
	}
	new = realloc(new, sizeof(char *) * size);
	new[size - 1] = NULL;
	return (new);
}