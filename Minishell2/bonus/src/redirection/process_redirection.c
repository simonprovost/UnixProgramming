/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

redirect_t func_redirect[] =
{
	{SEMICOLON, manage_semicolon},
	{SRR, manage_right},
	{DRR, manage_right},
	{PIPE, manage_pipe},
	{SRL, manage_left},
	{DRL, manage_double_left_redirection},
	{0, 0}
};

void proccess_pointer_tab_function(info_shell_t *info_shell,
binary_tree_t *tree, hashmap_t *hashmap, int fd_out)
{
	int j = info_shell->pos_pointer;

	if (tree->operator == SRL)
		info_shell->file_name = my_strdup(!tree->tright->args
		? "" : tree->tright->args);
	func_redirect[j].my_func(tree, info_shell, hashmap, fd_out);
	if (info_shell->error == 1)
		proccess_exec_node(tree, info_shell, hashmap, fd_out);
}

int proccess_exec_node(binary_tree_t *tree, info_shell_t *info_shell,
hashmap_t *hashmap, int fd_out)
{
	if (!tree || !info_shell->env || !hashmap || info_shell->error == 1) {
		close (fd_out);
		return (info_shell->return_value);
	}
	for (int j = 0 ; func_redirect[j].balise != 0 ; j++) {
		if (func_redirect[j].balise == tree->operator) {
			info_shell->pos_pointer = j;
			proccess_pointer_tab_function(info_shell, tree,
			hashmap, fd_out);
			info_shell->check_if_something_happened = 1;
		}
		info_shell->check_if_something_happened = 0;
	}
	if (exec_last_node(tree, hashmap, info_shell, fd_out) != 99)
		return (info_shell->return_value);
	return (info_shell->return_value);
}

int process_redirection(info_shell_t *info_shell, hashmap_t *hashmap,
int fd_out)
{
	if (error_handling_redirect(info_shell) != 0)
		return (info_shell->return_value);
	if (parser_line(info_shell) == 84)
		return (84);
	if (proccess_exec_node(info_shell->tree_args,
	info_shell, hashmap, fd_out) != 0) {
		return (info_shell->return_value);
	}
	return (0);
}