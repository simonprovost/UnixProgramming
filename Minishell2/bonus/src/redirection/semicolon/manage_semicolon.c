/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void exec_left_branch(info_shell_t *info_shell, binary_tree_t *tree,
int fd_out, hashmap_t *hashmap)
{
	if (info_shell->check_if_something_happened == 0 &&
	tree->tleft->args && (process_no_builtin(hashmap,
	tree->tleft->args, info_shell)) == 84) {
		info_shell->check_if_something_happened = 0;
		proccess_exec_node(tree->tright, info_shell, hashmap, fd_out);
	}
	if (info_shell->check_if_something_happened == 0 &&
	tree->tleft->args &&
	(process_builtin(hashmap, tree->tleft->args, info_shell)) != 0) {
		info_shell->check_if_something_happened = 0;
		proccess_exec_node(tree->tright, info_shell, hashmap, fd_out);
	}
	proccess_exec_node(tree->tright, info_shell, hashmap, fd_out);
}

void exec_right_branch(info_shell_t *info_shell, binary_tree_t *tree,
int fd_out, hashmap_t *hashmap)
{
	proccess_exec_node(tree->tleft, info_shell, hashmap, fd_out);
	if (tree->tright->args && (process_no_builtin(hashmap,
	tree->tright->args, info_shell)) == 84)
		info_shell->check_if_something_happened = 0;
	else if (tree->tright->args && (process_builtin(hashmap,
	tree->tright->args, info_shell)) != 0)
		info_shell->check_if_something_happened = 0;
}

int manage_semicolon(binary_tree_t *tree, info_shell_t *info_shell,
hashmap_t *hashmap, int fd_out)
{
	if (tree->tleft && tree->tleft->args != NULL &&
	tree->tleft->parent->operator == ';') {
		exec_left_branch(info_shell, tree, fd_out, hashmap);
	} else if (tree->tright && tree->tright->args != NULL &&
	tree->tright->parent->operator == ';'){
		exec_right_branch(info_shell, tree, fd_out, hashmap);
	} else
		proccess_exec_node(tree->tleft, info_shell, hashmap, fd_out);
	return (0);
}