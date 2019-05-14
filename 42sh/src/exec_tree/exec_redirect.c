/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exec_redirect
*/

#include "42sh.h"

void exec_right_redirect(btree_t *redirect, shell_t shell, int *ret_value)
{
	int fd = open(redirect->right->cmd,
					O_WRONLY | O_TRUNC | O_CREAT, 00664);

	redirect->left->fd[1] = fd;
	exec_tree(redirect->left, shell, ret_value);
	close(fd);
}

void exec_double_right_redirect(btree_t *redirect, shell_t shell,
								int *ret_value)
{
	int fd = open(redirect->right->cmd,
					O_WRONLY | O_CREAT | O_APPEND, 00664);

	redirect->left->fd[1] = fd;
	exec_tree(redirect->left, shell, ret_value);
	close(fd);
}

void exec_left_redirect(btree_t *redirect, shell_t shell, int *ret_value)
{
	int fd = open(redirect->right->cmd, O_RDONLY);

	if (fd == -1) {
		my_printf("%s: No such file or directory.\n",
							redirect->right->cmd);
		*ret_value = 1;
		return;
	}
	redirect->left->fd[0] = fd;
	exec_tree(redirect->left, shell, ret_value);
	close(fd);
}