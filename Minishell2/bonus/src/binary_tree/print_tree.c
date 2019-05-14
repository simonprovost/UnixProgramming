/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void print_tree_postfix(binary_tree_t *tr)
{
	if (tr == NULL)
		return;
	if (tr->parent != NULL)
		if (tr->parent->operator == 0)
			my_printf("[%c] ->%s\n", '0',
			tr->args == NULL ? "NULL" : tr->args);
		else
			my_printf("[%c] ->%s\n", tr->parent->operator,
			tr->args == NULL ? "NULL" : tr->args);
	else
		my_printf("{%c} && {%s} \n",
		tr->operator, tr->args == NULL ? "NULL" : tr->args);
	if (tr->tright != NULL) {
		my_printf("right\t");
		print_tree_postfix(tr->tright);
	}
	if (tr->tleft != NULL) {
		my_printf("left\t");
		print_tree_postfix(tr->tleft);
	}
}
