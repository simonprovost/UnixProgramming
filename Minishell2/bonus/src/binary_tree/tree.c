/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

binary_tree_t *create_new_tree(char operator, char *args)
{
	binary_tree_t *tr = malloc(sizeof(*tr));

	if (tr == NULL) {
		my_printf("malloc failed.\n");
		exit (84);
	}
	if (args) {
		my_epur_str(args);
	}
	operator != 0 ? (tr->operator = operator) : (tr->operator = 0);
	args != NULL ? (tr->args = my_strdup(args)) :  (tr->args = NULL);
	tr->parent = NULL;
	tr->tleft = NULL;
	tr->tright = NULL;
	return (tr);
}

void destroy_binary_tree(binary_tree_t *tr)
{
	if (tr == NULL)
		return;
	destroy_binary_tree(tr->tleft);
	destroy_binary_tree(tr->tright);
	free(tr->args);
	free(tr);
}