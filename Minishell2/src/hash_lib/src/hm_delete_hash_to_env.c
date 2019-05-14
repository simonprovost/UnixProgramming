/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"


char **update_my_env_delete_case(char *key, hashmap_t *hashmap, char **env)
{
	char **my_env = malloc(sizeof(char *) * (count_env(env) - 1) + 1);
	char *line = NULL;
	int i = 0;

	while (*env) {
		if (((get_anything_value(hashmap,
		my_key_copy(*env, '='))) == NULL)
		|| my_strcmp(*env, key) == 0) {
			(void)*env++;
			continue;
		}
		line = my_strcat(my_strcat(my_key_copy(*env, '='), "="),
		get_anything_value(hashmap, my_key_copy(*env, '=')));
		my_env[i] = malloc(sizeof(char) * my_strlen(line) + 1);
		my_env[i++] = my_strdup(line);
		(void)*env++;
	}
	my_env[i] = NULL;
	free (line);
	return (my_env);
}

void free_case(my_bucket_t *current)
{
	if (current->key != NULL)
		free (current->key);
	if (current->value != NULL)
		free (current->value);
}

int special_case_delete(hashmap_t *hashmap, char *key)
{
	int i = hashmap->size;
	my_bucket_t *current = NULL;

	if (key[0] == '*' && key[1] == 0) {
		for (; i != 0 ; i--) {
			current = hashmap->data[hashmap->size - i];
			current ? free_case(current) : 0;
		}
		return (1);
	}
	return (0);
}

char **delete_case_hashmap(hashmap_t *hashmap, char *key, char **env)
{
	int i = hashmap->size;
	my_bucket_t *current = NULL;

	if (special_case_delete(hashmap, key) == 1)
		return (update_my_env_delete_case(key, hashmap, env));
	if (get_anything_value(hashmap, key) == NULL)
		return (env);
	for (; i != 0 ; i--) {
		current = hashmap->data[hashmap->size - i];
		if (hashmap->data[hashmap->size - i]
		&& my_strcmp(key, hashmap->data[hashmap->size - i]->key) == 0) {
			free (current->key);
			current->mallocated == 1 ? free (current->value) : 0;
			break;
		}
	}
	return (update_my_env_delete_case(key, hashmap, env));
}
