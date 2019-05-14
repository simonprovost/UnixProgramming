/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** sort_lvar.c
*/

#include "my.h"
#include "42sh.h"

int is_sorted_lvar(ll_lvar_t *lvar)
{
	ll_lvar_t *tmp = lvar->next;

	if (tmp == NULL)
		return (1);
	while (tmp->next) {
		if (strcmp(tmp->name, tmp->next->name) > 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void swap_elem_lvar(ll_lvar_t *lvar1, ll_lvar_t *lvar2)
{
	char *sname = NULL;
	char *svalue = NULL;

	sname = lvar1->name;
	svalue = lvar1->value;
	lvar1->name = lvar2->name;
	lvar1->value = lvar2->value;
	lvar2->name = sname;
	lvar2->value = svalue;
}

void sort_lvar_core(ll_lvar_t *tmp)
{
	while (tmp->next) {
		if (strcmp(tmp->name, tmp->next->name) > 0)
			swap_elem_lvar(tmp, tmp->next);
		tmp = tmp->next;
	}
}

void sort_lvar(ll_lvar_t *lvar)
{
	ll_lvar_t *tmp = NULL;

	while (is_sorted_lvar(lvar) == 0) {
		tmp = lvar->next;
		sort_lvar_core(tmp);
	}
}