/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char **replace_case_hashmap(hashmap_t *hashmap, char *key, char *new_value,
char **env)
{
	for (int i = hashmap->size ; i != 0 ; i--) {
		if (hashmap->data[hashmap->size - i] &&
		my_strcmp(key, hashmap->data[hashmap->size - i]->key) == 0) {
			hashmap->data[hashmap->size - i]->value =
			my_strdup(new_value);
			break;
		}
	}
	return (fill_env_with_hashmap(hashmap, env));
}
