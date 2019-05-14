/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int count_tree_nodes(binary_tree_t *tr)
{
	if (tr == NULL)
		return (0);
	return (count_tree_nodes(tr->tleft) + count_tree_nodes(tr->tright) + 1);
}