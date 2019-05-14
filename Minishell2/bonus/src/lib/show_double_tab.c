/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void print_tab(char **tab)
{
	while (*tab) {
		if (!*tab)
			return;
		my_printf("%s\n", *tab);
		(void)*tab++;
	}
}