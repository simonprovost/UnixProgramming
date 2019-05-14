/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** create_env
*/

#include "42sh.h"

void set_new_elem_name(env_t *new_elem, char *str)
{
	int len = 0;

	for (len = 0; str[len] && str[len] != '='; len++);
	new_elem->name = malloc(sizeof(char) * len + 1);
	for (len = 0; str[len] && str[len] != '='; len++)
		new_elem->name[len] = str[len];
	new_elem->name[len] = 0;
}

void set_new_elem_value(env_t *new_elem, char *str)
{
	int len = 0;
	int i = 0;
	int save = 0;

	for (i = 0; str[i] && str[i] != '='; i++);
	i++;
	save = i;
	if (!str[i]) {
		new_elem->value = NULL;
		return;
	}
	for (len = 0; str[i]; i++)
		len++;
	new_elem->value = malloc(sizeof(char) * len + 1);
	for (i = 0; str[save]; save++) {
		new_elem->value[i] = str[save];
		i++;
	}
	new_elem->value[i] = 0;
}

void add_elem(env_t *list, char **str, int i)
{
	env_t *tmp = malloc(sizeof(*tmp));

	while (list->next)
		list = list->next;
	set_new_elem_name(tmp, str[i]);
	set_new_elem_value(tmp, str[i]);
	list->next = tmp;
	tmp->next = NULL;
}

env_t *create_list(char **str)
{
	env_t *list = malloc(sizeof(*list));
	int i = 0;

	list->value = NULL;
	list->name = NULL;
	list->next = NULL;
	while (str[i]) {
		add_elem(list, str, i);
		i++;
	}
	return (list);
}