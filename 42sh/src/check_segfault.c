/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** PSU_minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int check_segfault(int loc)
{
	int a = 0;
	int ret = 0;

	ret = WEXITSTATUS(loc);
	if (WTERMSIG(loc) == SIGSEGV) {
		my_printf("Segmentation fault");
		ret = 139;
		a = 1;
	} else if (WTERMSIG(loc) == SIGFPE) {
		my_printf("Floating exception");
		ret = 136;
		a = 1;
	}
	if (WCOREDUMP(loc))
		my_printf(" (core dumped)");
	(a == 1 ? my_putchar('\n') : 0);
	return (ret);
}
