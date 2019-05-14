/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

binary_tree_t *binary_parser_semicolon(char *line_tmp, binary_tree_t *tree)
{
	for (int i = my_strlen(line_tmp) ; i ; i--) {
		if (line_tmp[i] == SEMICOLON) {
			line_tmp[i] = 0;
			my_epur_str(tree->args);
			tree = join_tree(new_branch(0, my_strdup(line_tmp),
			tree), new_branch(0, my_strdup(tree->args + i + 1),
			tree), SEMICOLON, NULL);
			tree->tleft = load_binary_args(tree->tleft);
			tree->tright = load_binary_args(tree->tright);
			return (tree);
		}
	}
	return (tree);
}

binary_tree_t *load_binary_args(binary_tree_t *tree)
{
	char *line_tmp = NULL;
	int supp = 0;

	if (!tree->args)
		return (tree);
	line_tmp = my_strdup(tree->args);
	if (((count_op(line_tmp) == 0)
	|| (tree->args != NULL)) && (count_op(tree->args) == 0))
		return (tree);
	tree = binary_parser_semicolon(line_tmp, tree);
	if (!tree->args)
		return (tree);
	line_tmp = my_strdup(tree->args);
	if (((count_op(line_tmp) == 0)
	|| (tree->args != NULL)) && (count_op(tree->args) == 0))
		return (tree);
	return (binary_parser_pipe_redirect(tree->args
	? tree->args : line_tmp, tree, supp));
}

int parser_line(info_shell_t *info_shell)
{
	binary_tree_t *tree = create_new_tree(0, info_shell->line);

	if (!tree || !info_shell->line)
		return (84);
	info_shell->tree_args = load_binary_args(tree);
	if (!info_shell->tree_args)
		return (84);
	return (0);
}