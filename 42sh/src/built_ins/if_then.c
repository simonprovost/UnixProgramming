/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

char *delete_all_parenthese(char **str, int *parenthesis)
{
	char *tmp = NULL;

	if (!str)
		return (NULL);
	tmp = convert_tab_to_string(str);
	for (int i = 0 ; tmp[i] ; i++)
		if (tmp[i] == ')' || tmp[i] == '(') {
			*parenthesis = 1;
			tmp[i] = 32;
		}
	tmp = my_clean_str(tmp);
	return (tmp);
}

int check_then(char **s)
{
	if (!s || my_tablen(s) < 4)
		return (1);
	if (s[4] && strcmp(s[4], "then") == 0)
		return (0);
	return (1);
}

int process_then(char *str, shell_t shell)
{
	char **tmp = NULL;
	int err = 0;

	if (str && strncmp(str, "else if", 7) == 0) {
		tmp = my_str_to_word_array(str + 4, 32);
		if (check_error_handling_if(tmp) != 0) {
			free (tmp);
			return (1);
		}
		if_func(tmp, shell, &err);
		free (tmp);
		return (1);
	}
	return (0);
}

int check_then_if(char **s, shell_t shell)
{
	char *input = NULL;

	if (!s)
		return (84);
	if (check_then(s) != 0)
		return (0);
	isatty(0) ? write (1, "if? ", 4) : 0;
	if ((input = get_next_line(stdin)) == NULL)
		return (1);
	while (input != NULL && ((my_strcmp(input, "endif") != 0) &&
	(my_strcmp(input, "else") != 0))) {
		if (process_then(input, shell) != 0)
			break;
		isatty(0) ? write (1, "if? ", 4) : 0;
		if ((input = get_next_line(stdin)) == NULL)
			return (1);
	}
	return (0);
}
