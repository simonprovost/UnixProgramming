/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exec_pipe
*/

#include "42sh.h"

void exec_pipe(btree_t *pipe, shell_t shell, int *ret_value)
{
	pid_t pid = 0;

	if (set_pipefd(pipe) == 1) {
		*ret_value = 1;
		return;
	}
	pid = fork();
	if (!pid) {
		exec_tree(pipe->left, shell, ret_value);
		close(pipe->left->fd[1]);
		exit(0);
	}
	close(pipe->left->fd[1]);
	exec_tree(pipe->right, shell, ret_value);
	waitpid(pid, NULL, 0);
}