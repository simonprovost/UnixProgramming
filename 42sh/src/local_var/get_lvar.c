/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** get_lvar
*/

#include "42sh.h"

char *get_lvar(char *name, ll_lvar_t *list)
{
	while (list) {
		if (list->name && !my_strcmp(list->name, name))
			break;
		list = list->next;
	}
	if (list == NULL)
		return (NULL);
	return (list->value);
}