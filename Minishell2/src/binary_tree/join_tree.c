/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

binary_tree_t *join_tree(binary_tree_t *left, binary_tree_t *right,
char operator, char *args)
{
	binary_tree_t *tr = create_new_tree(operator, args);

	tr->tleft = left;
	tr->tright = right;
	if (left != NULL)
		left->parent = tr;
	if (right != NULL)
		right->parent = tr;
	return (tr);
}