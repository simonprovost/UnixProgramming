/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** error_handling
*/

#include "42sh.h"

int check_bad_pipes(btree_t *node, int error)
{
	if (!error && !my_strcmp(node->op, "&&")
	&& !node->left->op && (!node->left->cmd || !node->left->cmd[0])
	&& !node->right->op && (!node->right->cmd || !node->right->cmd[0]))
		return (0);
	if (!error && (!my_strcmp(node->op, "|")
	|| !my_strcmp(node->op, "||") || !my_strcmp(node->op, "&&"))
	&& ((!node->left->op && (!node->left->cmd || !node->left->cmd[0]))
	|| (!node->right->op && (!node->right->cmd || !node->right->cmd[0])))) {
		my_printf("Invalid null command.\n");
		return (1);
	}
	return (0);
}

int check_bad_redirects(btree_t *node, int error)
{
	if (!error && (!my_strcmp(node->op, ">") || !my_strcmp(node->op, ">>")
	|| !my_strcmp(node->op, "<") || !my_strcmp(node->op, "<<"))
	&& ((!node->left->op && (!node->left->cmd || !node->left->cmd[0]))
	|| (!node->right->op && (!node->right->cmd || !node->right->cmd[0])))) {
		my_printf("Missing name for redirect.\n");
		return (1);
	}
	if (!error && (!my_strcmp(node->op, ">") || !my_strcmp(node->op, ">>")
	|| !my_strcmp(node->op, "<") || !my_strcmp(node->op, "<<"))
	&& ((!my_strcmp(node->left->op, ">") || !my_strcmp(node->left->op, ">>")
	|| !my_strcmp(node->left->op, "<") || !my_strcmp(node->left->op, "<<"))
	|| (!my_strcmp(node->right->op, ">")
	|| !my_strcmp(node->right->op, ">>") || !my_strcmp(node->right->op, "<")
	|| !my_strcmp(node->right->op, "<<")))) {
		my_printf("Ambiguous %s redirect.\n", !my_strcmp(node->op, ">")
		|| !my_strcmp(node->op, ">>") ? "output" : "input");
		return (1);
	}
	return (0);
}

int btree_error_handling(btree_t *tree, int recurse)
{
	static int error = 0;

	if (!recurse)
		error = 0;
	if (check_bad_pipes(tree, error))
		error = 1;
	if (check_bad_redirects(tree, error))
		error = 1;
	if (tree->left)
		btree_error_handling(tree->left, 1);
	if (tree->right)
		btree_error_handling(tree->right, 1);
	return (error);
}