/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** inhibitors
*/

#include "42sh.h"

char *inhibitors_getline(void)
{
	char *str = NULL;

	if (isatty(STDIN_FILENO))
		my_printf("? ");
	str = get_next_line(stdin);
	return (str);
}

void inhibitors_core(char **str, int *i)
{
	char *tmp = NULL;
	char *line = NULL;

	if (!(*str)[*i + 1]) {
		(*str)[*i] = 0;
		line = inhibitors_getline();
		*i -= 1;
		*str = my_strcat(*str, line);
		free(line);
		return;
	}
	tmp = strdup(*str + *i + 2);
	*str = realloc(*str, strlen(*str) + 2);
	(*str)[*i] = '\'';
	(*str)[*i + 2] = '\'';
	(*str)[*i + 3] = 0;
	strcat(*str, tmp);
	free(tmp);
	*i += 2;
}

void parse_inhibitors(char **str)
{
	for (int i = 0; (*str)[i]; i++) {
		update_iterator_for_quotes(*str, &i);
		if ((*str)[i] == '\\')
			inhibitors_core(str, &i);
	}
}