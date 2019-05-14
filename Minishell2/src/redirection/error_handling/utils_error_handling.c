/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int check_another_next_elem(char **tab, info_shell_t *info_shell, int i)
{
	if (is_op_or_arg(tab[i]) == 1 && is_op_or_arg(tab[i + 2]) == 1
	&& tab[i][0] != PIPE
	&& is_same_op(tab[i], tab[i + 2]) == 1) {
		my_printf("Ambiguous %s redirect.\n", tab[i][0] == SRR ?
		"output" : "input");
		info_shell->return_value = 1;
		return (info_shell->return_value);
	}
	return (0);
}

int is_op_or_arg(char *line)
{
	if (!line)
		return (0);
	if ((((line[0] == (PIPE))
	|| (line[0] == SRL)
	|| (line[0] == SRR)) && line[1] == 0)
	|| (line[0] == SRL && line[1] == SRL && line[2] == 0)
	|| (line[0] == SRR && line[1] == SRR && line[2] == 0))
		return (1);
	return (0);
}

int is_same_op(char *line, char *line_next)
{
	if (!line || !line_next)
		return (0);
	if (my_strcmp(line, line_next) == 0)
		return (1);
	if (is_op_or_arg(line) == 1 && is_op_or_arg(line_next) == 1
	&& line[0] == line_next[0])
		return (1);
	return (0);
}

int size_tab(char **tab)
{
	int i = 0;

	if (!tab)
		return (0);
	for (; tab[i] ; i++);
	return (i);
}

int is_arg(char *line)
{
	if (!line || is_op_or_arg(line) == 1)
		return (0);
	return (1);
}
