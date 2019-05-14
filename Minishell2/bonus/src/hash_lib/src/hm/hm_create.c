/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

hashmap_t *hm_create(unsigned int size)
{
	hashmap_t *hashmap = malloc(sizeof(*hashmap));

	if (!hashmap)
		return (NULL);
	hashmap->size = size;
	hashmap->data = malloc(size * sizeof(*(hashmap->data)));
	if (!hashmap->data)
		return (NULL);
	for (int i = 0; i < (int)size; ++i)
		hashmap->data[i] = NULL;
	return (hashmap);
}

my_bucket_t *hm_create_bucket(char *key, void *value)
{
	my_bucket_t *new = malloc(sizeof(*new));

	new->key = key;
	new->value = value;
	new->next = NULL;
	if (my_strcmp((char *)value, "") == 0)
		new->mallocated = 0;
	else
		new->mallocated = 1;
	return (new);
}