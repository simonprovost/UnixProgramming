/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** unalias.c
*/

#include "my.h"
#include "42sh.h"

void delete_alias(char *str, ll_alias_t *lla)
{
	ll_alias_t *tmp = lla;

	while (tmp->next) {
		if (strcmp(tmp->next->name, str) == 0) {
			tmp->next = tmp->next->next;
			return;
		}
		tmp = tmp->next;
	}
}

void unalias_loop(char **str, ll_alias_t *lla)
{
	int i = 1;

	while (str[i]) {
		delete_alias(str[i], lla);
		i++;
	}
}

void unalias_func(char **str, shell_t shell, int *ret_value)
{
	if (my_tablen(str) == 1) {
		printf("unalias: Too few arguments.\n");
		*ret_value = 1;
		return;
	} else {
		unalias_loop(str, shell.aliases);
	}
}