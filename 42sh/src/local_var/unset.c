/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** unset.c
*/

#include "my.h"
#include "42sh.h"

void delete_lvar(char *name, ll_lvar_t *lvar)
{
	ll_lvar_t *tmp = lvar;

	while (tmp->next) {
		if (strcmp(name, tmp->next->name) == 0) {
			tmp->next = tmp->next->next;
			return;
		}
		tmp = tmp->next;
	}
}

void unset_func(char **str, shell_t shell, int *ret_value)
{
	if (my_tablen(str) == 1) {
		printf("%s: Too few arguments.\n", str[0]);
		*ret_value = 1;
		return;
	}
	for (int i = 1; i < my_tablen(str); i++)
		delete_lvar(str[i], shell.local_var);
}