/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

hashmap_t *fill_hashmap_with_env(hashmap_t *hashmap, char **env)
{
	char *value = NULL;
	char *key = NULL;

	if (env == NULL)
		return (NULL);
	for (int i = 0 ; env[i] ; i++) {
		key = my_key_copy(env[i], '=');
		value = my_value_copy(env[i], '=');
		hm_add(hashmap, key, value);
	}
	return (hashmap);
}

void free_value(char *key)
{
	free (key);
	key = NULL;
}

char **fill_env_with_hashmap(hashmap_t *hashmap, char **env)
{
	char **my_env = malloc(sizeof(char *) * (count_env(env) + 1));
	char *get_value = NULL;
	char *key = NULL;
	int j = 0;
	int i = 0;

	for (; env[j] ; j++) {
		if (!env[j])
			break;
		key = my_key_copy(env[j], '=');
		get_value = hm_get(hashmap, key);
		if (!get_value)
			continue;
		key = my_strcat(key, "=");
		my_env[i++] = my_strdup(my_strcat(key, get_value));
	}
	my_env[i] = NULL;
	free_value(key);
	return (my_env);
}
