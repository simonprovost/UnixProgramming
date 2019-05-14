/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** alias_loop.c
*/

#include "my.h"
#include "42sh.h"

int 	alias_is_another(char *alias, ll_alias_t *lla)
{
	for (ll_alias_t *tmp = lla->next; tmp; tmp = tmp->next) {
		if (strcmp(tmp->name, alias) == 0)
			return (1);
	}
	return (0);
}

ll_alias_t *step_up_alias(char *alias, ll_alias_t *lla, int *ret)
{
	ll_alias_t *tmp = lla->next;

	while (tmp) {
		if (strcmp(tmp->alias, tmp->name) == 0)
			*ret = -1;
		if (strcmp(alias, tmp->name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int 	alias_loop(ll_alias_t *tmp, ll_alias_t *lla)
{
	int pass = 0;
	char *name = malloc(sizeof(char) * strlen(tmp->name) + 1);
	int ret = 0;

	if (strcmp(tmp->name, tmp->alias) == 0)
		return (2);
	strcpy(name, tmp->name);
	while (alias_is_another(tmp->alias, lla) == 1) {
		tmp = step_up_alias(tmp->alias, lla, &ret);
		if (ret == -1) {
			return (0);
		}
		if (strcmp(name, tmp->name) == 0)
			pass++;
		if (pass >= 2)
			return (1);
	}
	return (0);
}
