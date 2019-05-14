/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exec_double_left_redirection
*/

#include "42sh.h"

void read_tmp_file(btree_t *redirect, shell_t shell, int *ret_value)
{
	int fd = open(".tmp_redirect/tmp_a839", O_RDONLY);

	redirect->left->fd[0] = fd;
	exec_tree(redirect->left, shell, ret_value);
	close(fd);
}

void exec_double_left_redirect(btree_t *redirect, shell_t shell, int *ret_value)
{
	char *str = NULL;
	int fd = open(".tmp_redirect/tmp_a839", O_RDWR | O_TRUNC);

	while (1) {
		if (isatty(STDIN_FILENO))
			my_printf("? ");
		str = get_next_line(stdin);
		if (!str || !my_strcmp(str, redirect->right->cmd))
			break;
		write(fd, str, my_strlen(str));
		write(fd, "\n", 1);
		free(str);
	}
	if (str)
		free(str);
	close(fd);
	read_tmp_file(redirect, shell, ret_value);
}