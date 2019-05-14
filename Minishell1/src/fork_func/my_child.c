/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"


void my_child(int status)
{
	int check = 0;

	if (status == 139) {
		my_printf(SEG);
		check = 1;
	} else if (status == 136) {
		my_printf(FLT_PT);
		check = 1;
	}
	if (WCOREDUMP(status))
		my_printf(" (core dumped)");
	check == 1 ? my_putchar('\n') : 0;
}