/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void free_tab(char **tab)
{
	if (!tab)
		return;
	for (int i = 0; tab[i] != NULL; i++) {
		if (tab[i] != NULL && tab[i][0] != 0)
			free(tab[i]);
	}
	free(tab);
}

void bucket_destroy(my_bucket_t *bucket)
{
	my_bucket_t *tmp = bucket;

	while (bucket && tmp != NULL) {
		tmp = bucket;
		free(tmp->value);
		free(tmp->key);
		bucket = bucket->next;
		free(tmp);
	}
}

void destroy_ll_bucket(hashmap_t *hashmap)
{
	for (int i = hashmap->size ; i != 0 ; i--)
		if (hashmap->data[hashmap->size - i])
			bucket_destroy(hashmap->data[hashmap->size - i]);
}

void hm_destroy(hashmap_t *hashmap)
{
	destroy_ll_bucket(hashmap);
	free (hashmap->data);
	free(hashmap);
}
