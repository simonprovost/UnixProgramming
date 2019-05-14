/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int check_brackets(char *cmd)
{
	for (int i = 0 ; cmd[i] ; i++) {
		update_iterator_for_quotes(cmd, &i);
		if (cmd[i] == '[' && cmd[i + 1] == ']')
			return (1);
	}
	return (0);
}

int check_glob_ref(char *cmd)
{
	if (!cmd)
		return (84);
	for (int i = 0 ; cmd[i] ; i++) {
		update_iterator_for_quotes(cmd, &i);
		if (cmd[i] == '*' || cmd[i] == '?' || cmd[i] == '['
		|| cmd[i] == ']')
			return (1);
	}
	return (0);
}

char *parse_glob(char *cmd, int clean)
{
	char **tab_cmd = NULL;
	char *ret = NULL;
	static int pos_tab = 0;

	if (!cmd || clean == 1) {
		pos_tab = 0;
		return (NULL);
	}
	tab_cmd = my_str_to_word_array(cmd, 32);
	for (int i = clean == 2 ? 0 : pos_tab ; tab_cmd[i] ; i++) {
		if (check_glob_ref(tab_cmd[i]) == 1) {
			pos_tab = i + 1;
			ret = strdup(tab_cmd[i]);
			my_free_tab(tab_cmd);
			return (ret);
		}
	}
	my_free_tab(tab_cmd);
	return (NULL);
}

int count_glob(char *cmd)
{
	char **tab_cmd = NULL;
	int wildcard = 0;

	if (!cmd)
		exit (84);
	tab_cmd = my_str_to_word_array(cmd, 32);
	for (int i = 0 ; tab_cmd[i] ; i++) {
		if (check_glob_ref(tab_cmd[i]) == 1)
			wildcard++;
	}
	my_free_tab(tab_cmd);
	return (wildcard);
}