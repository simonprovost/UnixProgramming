/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** scripting.c
*/

#include "42sh.h"

void replace_argument(char **parsed, char **arguments, int i)
{
	int arg = parsed[i][1] - '0';
	int max = my_tablen(arguments);
	char *tmp = NULL;

	if (arg < 0)
		return;
	parsed[i][0] = ' ';
	parsed[i][1] = ' ';
	if (arg <= max) {
		tmp = parsed[i];
		parsed[i] = my_strcat(tmp, arguments[arg]);
		if (!parsed[i])
			exit(84);
		free(tmp);
		if (!parsed[i])
			exit(84);
	}
}

void seek_arguments(char **parsed, char **arguments)
{
	for (int i = 0; parsed[i]; i++) {
		if (parsed[i][0] == '$')
			replace_argument(parsed, arguments, i);
	}
}

char *replace_arguments(char *buffer, char **arguments)
{
	char *cmd = NULL;
	char **parsed = my_str_to_word_array(buffer, ' ');

	if (!parsed)
		return (NULL);
	seek_arguments(parsed, arguments);
	cmd = convert_tab_to_string(parsed);
	return (cmd);
}

int seek_script(shell_t shell, char **binary, int *ret_value)
{
	FILE *file = NULL;
	char *buffer = NULL;

	if (!binary || !binary[0])
		return (1);
	file = fopen(binary[0], "r");
	if (!file || !(buffer = get_next_line(file)) || !buffer[0]
	|| (buffer[1] == 'E' && buffer[2] == 'L' && buffer[3] == 'F'))
		return (1);
	buffer = replace_arguments(buffer, binary);
	if (!buffer)
		return (0);
	parse_cmd(shell, buffer, ret_value);
	while ((buffer = get_next_line(file))) {
		buffer = replace_arguments(buffer, binary);
		if (!buffer)
			return (0);
		parse_cmd(shell, buffer, ret_value);
	}
	return (0);
}