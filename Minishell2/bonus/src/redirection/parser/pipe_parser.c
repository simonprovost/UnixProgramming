/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char parse_pipe_next(char *line_tmp, int *i, int *supp)
{
	char op_tmp = 0;

	if ((line_tmp[*i] == SRL && line_tmp[*i - 1] == SRL)
	|| (line_tmp[*i] == SRR && line_tmp[*i - 1] == SRR)) {
		*supp = 2;
		(line_tmp[*i] == SRR) ? (op_tmp = ']') : (op_tmp = '[');
		(*i) -= 1;
		return (op_tmp);
	} else {
		*supp = 1;
		op_tmp = line_tmp[*i];
	}
	return (op_tmp);
}

char update_args(char *line_tmp, binary_tree_t *tree)
{
	tree->args = my_strdup(line_tmp);
	return ('\0');
}

void recurs(binary_tree_t *tree)
{
	tree->tright = load_binary_args(tree->tright);
	tree->tleft = load_binary_args(tree->tleft);
}

binary_tree_t *binary_parser_pipe_redirect(char *line_tmp,
binary_tree_t *tree, int supp)
{
	char op_tmp;

	if (((count_op(line_tmp) == 0 || EMPTY_OP)))
		return (tree);
	for (int i = my_strlen(line_tmp) ; i ; i--) {
		if (line_tmp[i] == PIPE || line_tmp[i] == SRL
		|| line_tmp[i] == SRR
		|| (line_tmp[i] == SRL && line_tmp[i + 1] == SRL)
		|| (line_tmp[i] == SRR && line_tmp[i + 1] == SRR)) {
			op_tmp = parse_pipe_next(line_tmp, &i, &supp);
			line_tmp[i] = update_args(line_tmp, tree);
			tree = join_tree(new_branch(0, my_strdup(line_tmp),
			tree), new_branch(0, !tree->args ? NULL :
			my_strdup(tree->args + i + supp),
			tree), op_tmp, NULL);
			recurs(tree);
			return (tree);
		}
	}
	return (tree);
}
