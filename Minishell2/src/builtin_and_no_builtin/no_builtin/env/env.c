/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void manage_env(hashmap_t *hashmap, char *args, info_shell_t *info_shell)
{
	UNUSED(hashmap);
	UNUSED(args);
	print_tab(info_shell->env);
}