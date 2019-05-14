/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** echo
*/

#include "42sh.h"

void update_iterator_for_quotes(char *str, int *i)
{
	char quote = 0;

	if (str[*i] == '"' || str[*i] == '\'')
		quote = str[*i];
	else
		return;
	for (*i += 1; str[*i] && str[*i] != quote; *i += 1);
}

int check_glob(char *cmd)
{
	if (!cmd)
		return (84);
	for (int i = 0 ; cmd[i] ; i++) {
		update_iterator_for_quotes(cmd, &i);
		if (cmd[i] == '*' || cmd [i] == '?' || cmd[i] == '[' ||
		cmd[i] == ']')
			return (1);
	}
	return (0);
}

int process_globbing(char **cmd)
{
	int ret = 0;

	if (!cmd)
		return (84);
	if ((ret = check_glob(*cmd)) != 1)
		return (ret);
	if (process_glob(cmd) != 0)
		return (1);
	return (0);
}