/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void print_env(info_t *info)
{
	for (int i = 0; info->env[i] != NULL ; i++)
		my_printf("%s\n", info->env[i]);
}
