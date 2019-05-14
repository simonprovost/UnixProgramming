/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void child_dup(int *fd, int fd_out)
{
	dup2(fd_out, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
}

void not_found(binary_tree_t *tree, info_shell_t *info_shell)
{
	print_correct_file_error(tree->tright->args);
	info_shell->return_value = 1;
	my_printf(": Command not found.\n");
	info_shell->check_if_something_happened = 0;
}

void exec_child(info_shell_t *info_shell, hashmap_t *hashmap, binary_tree_t
*tree)
{
	if (info_shell->check_if_something_happened == 0) {
		if ((process_no_builtin(hashmap,
		tree->tright->args, info_shell)) == 84) {
			info_shell->check_if_something_happened = 0;
			(BUILTIN_L_R) || (B_ENV) ?
			exit (info_shell->return_value) : 0;
		}
	}
	if (info_shell->check_if_something_happened == 0) {
		if ((process_builtin(hashmap, tree->tright->args,
		info_shell)) != 0)
			(BUILTIN_L_R) || (B_ENV) ?
			exit (info_shell->return_value) : 0;
	}
	if (info_shell->check_if_something_happened == 0 &&
	info_shell->line[0] != 0) {
		not_found(tree,  info_shell);
		(BUILTIN_L_R) || (B_ENV) ? exit (info_shell->return_value) : 0;
	}
}

int manage_pipe(binary_tree_t *tree, info_shell_t *info_shell, hashmap_t
*hashmap, int fd_out)
{
	int fd[2];
	int pid = 0;
	int status = 0;

	pipe(fd);
	if ((BUILTIN_L_R) || (B_ENV))
		pid = fork();
	if (pid == 0) {
		child_dup(fd, fd_out);
		exec_child(info_shell, hashmap, tree);
		(BUILTIN_L_R) || (B_ENV) ? exit (info_shell->return_value) : 0;
	}
	close(fd[0]);
	close(fd_out);
	proccess_exec_node(tree->tleft, info_shell, hashmap, fd[1]);
	(BUILTIN_L_R) || (B_ENV) ? waitpid(pid, &status, 0) : 0;
	info_shell->return_value = status >= 256 ? status / 256 :
	info_shell->return_value;
	return (info_shell->return_value);
}