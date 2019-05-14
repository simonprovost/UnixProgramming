/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void show_double_tab(info_t *info)
{
	for (int j = 0; j <= info->size ; j++)
		my_printf("%s", info->info[j], j);
}