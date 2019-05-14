/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int check_another_elem(char **tab, info_shell_t *info_shell)
{
	for (int i = 0 ; tab[i] ; i++) {
		if (check_another_next_elem(tab, info_shell, i) != 0)
			return (info_shell->return_value);
		if (is_op_or_arg(tab[i]) == 1 && is_arg(tab[i + 1]) == 0
		&& is_arg(tab[i - 1]) == 1) {
			tab[i][0] != PIPE ? my_printf(MISSING_NAME)
			: my_printf(INVALID_CMD);
			info_shell->return_value = 1;
			return (info_shell->return_value);
		}
		if ((is_op_or_arg(tab[i]) == 1 && is_arg(tab[i - 1]) == 0)) {
			my_printf(INVALID_CMD);
			info_shell->return_value = 1;
			return (info_shell->return_value);
		}
	}
	return (0);
}

int ambiguous_redirect(int i, char *line)
{
	char first = line[i];
	char second = 0;

	if (!line[i + 1])
		return (0);
	second = line[i + 1];
	if ((first == PIPE && (second == SRL || second == 'L'))
	|| ((first == SRR || first == 'R') && second == PIPE))
		return (1);
	return (0);
}

int verif_op(char *line, info_shell_t *info_shell)
{
	for (int i = 0 ; line[i] ; i++) {
		if ((line[i] == line[i + 1] && line[i] != ';' &&
		line[i] != PIPE)
		|| ambiguous_redirect(i, line) == 1) {
			my_printf("Ambiguous %s redirect.\n",
			line[i] == SRR || line[i] == 'R' ? "output" : "input");
			info_shell->return_value = 1;
			return (84);
		}
	}
	return (0);
}

int check_first_elem(char **tab_line, info_shell_t *info_shell)
{
	if (!tab_line) {
		info_shell->return_value = 1;
		return (84);
	}
	if (((TAB == PIPE || TAB == SRL))
	|| (TAB == SRL && TAB1 == SRL && TAB2 == 0)
	|| (TAB == SRR && TAB1 == 0)
	|| ((TAB == SRR && TAB1 == SRR && TAB2 == 0))){
		TAB == SRL || TAB == SRR ? my_printf(MISSING_NAME) :
		my_printf(INVALID_CMD);
		info_shell->return_value = 1;
		return (info_shell->return_value);
	}
	return (0);
}

int error_handling_redirect(info_shell_t *info_shell)
{
	char **tab_line = NULL;
	char **tab_tmp = malloc(sizeof(char *) * 1024);

	if (!info_shell->line || info_shell->line[0] == 0)
		return (1);
	my_epur_str(info_shell->line);
	tab_line = str_to_word_array(info_shell->line);
	if (check_first_elem(tab_line, info_shell) != 0)
		return (info_shell->return_value);
	for (int i = 0 ; i < 1024 ; i++) {
		if (i < size_tab(tab_line))
			tab_tmp[i] = my_strdup(tab_line[i]);
		else
			tab_tmp[i] = NULL;
	}
	if (check_another_elem(tab_tmp, info_shell) != 0)
		return (info_shell->return_value);
	if (verif_op(load_op(info_shell->line), info_shell) == 84)
		return (info_shell->return_value);
	return (0);
}