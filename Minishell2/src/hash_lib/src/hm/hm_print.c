/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void print_hashmap(hashmap_t *hashmap, char **env)
{
	while (*env) {
		if ((get_anything_value(hashmap,
		my_key_copy(*env, '='))) == NULL) {
			(void)*env++;
			continue;
		}
		my_printf("%s=", my_key_copy(*env, '='));
		my_printf("%s\n", get_anything_value(hashmap,
		my_key_copy(*env++, '=')));
	}
}