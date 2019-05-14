/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exec_tree
*/

#include "42sh.h"

static const operator_t op_tab[] =
{
	{";", &exec_semicolon},
	{"|", &exec_pipe},
	{">", &exec_right_redirect},
	{"<", &exec_left_redirect},
	{">>", &exec_double_right_redirect},
	{"<<", &exec_double_left_redirect},
	{"&&", &exec_double_and},
	{"||", &exec_double_or},
	{NULL, NULL}
};

void exec_tree(btree_t *tree, shell_t shell, int *ret_value)
{
	char **word_tab = NULL;

	for (int i = 0; tree->op && op_tab[i].fptr; i++) {
		if (!my_strcmp(tree->op, op_tab[i].op)) {
			op_tab[i].fptr(tree, shell, ret_value);
			return;
		}
	}
	if (process_globbing(&tree->cmd)) {
		*ret_value = 1;
		return;
	}
	word_tab = my_str_to_word_array(tree->cmd, ' ');
	word_tab = parse_quotes(word_tab);
	if (check_built_ins(word_tab, shell, ret_value, tree->fd) == 1
	&& seek_script(shell, word_tab, ret_value) == 1)
		if (word_tab && word_tab[0])
			*ret_value = my_exec(word_tab, shell.env, tree->fd);
	my_free_tab(word_tab);
}