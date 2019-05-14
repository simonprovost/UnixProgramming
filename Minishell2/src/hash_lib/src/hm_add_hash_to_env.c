/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char *add_value_to_last_case(char *key, hashmap_t *hashmap, char *line)
{
	char *my_env = NULL;

	if ((get_anything_value(hashmap, key)) != NULL) {
		line = my_strcat(my_strcat(key, "="),
		get_anything_value(hashmap, key));
		my_env = malloc(sizeof(char) * my_strlen(line) + 1);
		my_env = my_strdup(line);
		my_env[my_strlen(line)] = 0;
	}
	return (my_env);
}

char **update_my_env_add_case(char *key, hashmap_t *hashmap, char **env)
{
	int size_env = count_env(env) + 1;
	char **my_env = malloc(sizeof(char *) * size_env + 1);
	char *line = NULL;
	int i = 0;

	while (*env) {
		if (((get_anything_value(hashmap,
		my_key_copy(*env, '='))) == NULL)) {
			(void)*env++;
			continue;
		}
		line = my_strcat(my_strcat(my_key_copy(*env, '='), "="),
		get_anything_value(hashmap, my_key_copy(*env, '=')));
		my_env[i++] = my_strdup(line);
		(void)*env++;
	}
	my_env[i++] = add_value_to_last_case(key, hashmap, line);
	my_env[i] = NULL;
	free(line);
	return (my_env);
}

char **add_value_to_env(hashmap_t *hashmap, char *key, char *value, char **env)
{
	if (hm_get(hashmap, key) == NULL) {
		hm_add(hashmap, my_strdup(key), value != NULL ?
		my_strdup(value) : "");
	} else
		return (replace_case_hashmap(hashmap, key, value, env));
	return (update_my_env_add_case(key, hashmap, env));
}