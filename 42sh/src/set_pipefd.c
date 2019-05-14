/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** set_pipefd
*/

#include "42sh.h"

int set_pipefd(btree_t *node)
{
	int pipefd[2];

	node->left->fd[0] = node->fd[0];
	node->right->fd[1] = node->fd[1];
	if (pipe(pipefd) == -1)
		exit(84);
	node->right->fd[0] = pipefd[0];
	node->left->fd[1] = pipefd[1];
	return (0);
}