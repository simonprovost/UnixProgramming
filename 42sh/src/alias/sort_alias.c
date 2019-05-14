/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** sort_alias.c
*/

#include "my.h"
#include "42sh.h"

int		is_sorted(ll_alias_t *lla)
{
	ll_alias_t *tmp = lla->next;

	if (tmp == NULL)
		return (1);
	while (tmp->next) {
		if (strcmp(tmp->name, tmp->next->name) > 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		swap_elem(ll_alias_t *tmp1, ll_alias_t *tmp2)
{
	char *sname = NULL;
	char *salias = NULL;
	int spar;

	sname = tmp1->name;
	salias = tmp1->alias;
	spar = tmp1->par;
	tmp1->name = tmp2->name;
	tmp1->alias = tmp2->alias;
	tmp1->par = tmp2->par;
	tmp2->name = sname;
	tmp2->alias = salias;
	tmp2->par = spar;
}

void		sort_lla(ll_alias_t *lla)
{
	ll_alias_t *tmp = NULL;

	while (is_sorted(lla) == 0) {
		tmp = lla->next;
		while (tmp->next) {
			if (strcmp(tmp->name, tmp->next->name) > 0) {
				swap_elem(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}

void 		my_free_lla(ll_alias_t *lla)
{
	ll_alias_t *tmp = NULL;

	while (lla) {
		tmp = lla;
		lla = lla->next;
		if (tmp && tmp->name)
			free(tmp->name);
		if (tmp && tmp->alias)
			free(tmp->alias);
		free(tmp);
	}
}