/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int err_handling_last(binary_tree_t *tree, int status,
info_shell_t *info_shell, int fd_out)
{
	if (tree->parent && tree->parent->operator == PIPE
	&& tree->parent->tright &&
	is_builtin(tree->parent->tright->args) == 1) {
		info_shell->return_value = status > 255 ? status - 255 : 0;
		if (fd_out != 1)
			close(fd_out);
		return (1);
	}
	return (0);
}

void exec_childlast_node(binary_tree_t *tree, hashmap_t *hashmap,
info_shell_t *info_shell, int fd_out)
{
	if (info_shell->check_if_something_happened == 0)
		if ((process_no_builtin(hashmap, tree->args, info_shell))
		== 84) {
			info_shell->check_if_something_happened = 0;
			(fd_out != info_shell->fd_fileno[1]) ?
			exit (info_shell->return_value) : 0;
		}
	if (info_shell->check_if_something_happened == 0)
		if ((process_builtin(hashmap, tree->args, info_shell)) != 0)
			(fd_out != info_shell->fd_fileno[1]) ?
			exit (info_shell->return_value) : 0;
	if (info_shell->check_if_something_happened == 0 &&
	info_shell->line[0] != 0) {
		print_correct_file_error(tree->args);
		my_printf(": Command not found.\n");
		info_shell->return_value = 1;
		info_shell->check_if_something_happened = 0;
		(fd_out != info_shell->fd_fileno[1]) ?
		exit (info_shell->return_value) : 0;
	}
}

void last_verif_of_last_node(info_shell_t *info_shell, int status,
int fd_out)
{
	info_shell->return_value = status > 255 ?
	status - 255 : 0;
	if (fd_out != 1)
		close(fd_out);
}

int exec_last_node(binary_tree_t *tree, hashmap_t *hashmap,
info_shell_t *info_shell, int fd_out)
{
	pid_t pid = 0;
	int status = 0;

	if (tree->operator == 0 && info_shell->error == 0) {
		if (err_handling_last(tree, status, info_shell, fd_out) != 0)
			return (info_shell->return_value);
		((fd_out != info_shell->fd_fileno[1]) ? (pid = fork()) :
		(pid = 0));
		if (pid == 0) {
			dup2(fd_out, 1);
			exec_childlast_node(tree, hashmap, info_shell, fd_out);
			(fd_out != info_shell->fd_fileno[1]) ?
			exit (info_shell->return_value) : 0;
		} else {
			(fd_out != info_shell->fd_fileno[1]) ?
			waitpid(pid, &status, 0) : 0;
			last_verif_of_last_node(info_shell, status, fd_out);
		}
	}
	return (42);
}
