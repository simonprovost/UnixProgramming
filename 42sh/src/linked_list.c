/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int size_list(env_t *list)
{
	int i = 0;

	while (list) {
		i++;
		list = list->next;
	}
	return (i);
}

void free_list(env_t *list)
{
	env_t *env = NULL;

	while (list) {
		env = list;
		list = list->next;
		if (env && env->name)
			free(env->name);
		if (env && env->value)
			free(env->value);
		free(env);
	}
}

char **list_to_2d_arr(env_t *list)
{
	char **tab_array = malloc(sizeof(char *) * (size_list(list) + 1));
	int i = 0;
	int j = 0;

	list = list->next;
	for (i = 0; list; i++) {
		tab_array[i] = malloc(sizeof(char) * (my_strlen(list->value)
						+ my_strlen(list->name) + 2));
		for (j = 0; list->name && list->name[j]; j++)
			tab_array[i][j] = list->name[j];
		tab_array[i][j] = '=';
		j++;
		for (int x = 0; list->value && list->value[x]; j++)
			tab_array[i][j] = list->value[x++];
		tab_array[i][j] = 0;
		list = list->next;
	}
	tab_array[i] = NULL;
	return (tab_array);
}
