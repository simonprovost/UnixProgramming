/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

binary_tree_t *new_branch(char operator, char *args, binary_tree_t *parent)
{
	binary_tree_t *tr = malloc(sizeof(*tr));

	if (tr == NULL) {
		my_printf("malloc Failed.\n");
		exit (84);
	}
	if (args) {
		my_epur_str(args);
	}
	operator != 0 ? (tr->operator = operator) : (tr->operator = 0);
	args != NULL ? (tr->args = my_strdup(args)) :  (tr->args = NULL);
	tr->parent = parent;
	tr->tleft = NULL;
	tr->tright = NULL;
	return (tr);
}