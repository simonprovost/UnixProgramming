/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** exec_semicolon
*/

#include "42sh.h"

void exec_semicolon(btree_t *semicolon, shell_t shell, int *ret_value)
{
	exec_tree(semicolon->left, shell, ret_value);
	exec_tree(semicolon->right, shell, ret_value);
}

void exec_double_and(btree_t *semicolon, shell_t shell, int *ret_value)
{
	exec_tree(semicolon->left, shell, ret_value);
	if (*ret_value != 0)
		return;
	exec_tree(semicolon->right, shell, ret_value);
}

void exec_double_or(btree_t *semicolon, shell_t shell, int *ret_value)
{
	exec_tree(semicolon->left, shell, ret_value);
	if (*ret_value == 0)
		return;
	*ret_value = 0;
	exec_tree(semicolon->right, shell, ret_value);
}