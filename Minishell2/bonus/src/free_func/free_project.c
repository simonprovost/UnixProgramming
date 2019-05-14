/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void free_all(char **my_env, hashmap_t *hashmap)
{
	free_tab(my_env);
	hm_destroy(hashmap);
}