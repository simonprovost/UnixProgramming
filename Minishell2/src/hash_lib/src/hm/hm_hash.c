/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

unsigned int hm_hash(hashmap_t *hashmap, char *key)
{
	unsigned long hash = 5381;
	int c = 0;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;
	return (hash % hashmap->size);
}