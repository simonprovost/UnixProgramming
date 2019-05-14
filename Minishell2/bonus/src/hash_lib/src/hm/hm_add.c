/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"


void hm_linked_list_add(my_bucket_t **list, my_bucket_t *bucket)
{
	bucket->next = *list;
	*list = bucket;
}

void hm_add(hashmap_t *hashmap, char *key, void *value)
{
	unsigned int i = hm_hash(hashmap, key);
	my_bucket_t *bucket = hm_get_bucket(hashmap, key);

	if (bucket == NULL)
		hm_linked_list_add(hashmap->data + i,
		hm_create_bucket(key, value));
	else {
		free(bucket->value);
		bucket->value = value;
	}
}