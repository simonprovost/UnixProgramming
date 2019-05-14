/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

my_bucket_t *hm_get_bucket(hashmap_t *hashmap, char *key)
{
	unsigned int i = hm_hash(hashmap, key);
	my_bucket_t *list = hashmap->data[i];

	while (list != NULL && my_strcmp(list->key, key) != 0)
		list = list->next;
	if (!list)
		return (NULL);
	return (list);
}

void *hm_get(hashmap_t *hashmap, char *key)
{
	my_bucket_t *bucket = NULL;

	if (!key)
		return (NULL);
	bucket = hm_get_bucket(hashmap, key);
	if (bucket == NULL)
		return (NULL);
	return (bucket->value);
}

char *get_anything_value(hashmap_t *hashmap, char *user_value)
{
	if (hm_get(hashmap, user_value) == NULL)
		return (NULL);
	else
		return ((char *)hm_get(hashmap, user_value));
}
