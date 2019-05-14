/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** PSU_minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

void sig_handler(int sig_num)
{
	if (sig_num == SIGINT) {
		my_putchar('\n');
		print_prompt(global_env);
	} else if (sig_num == SIGSEGV) {
		my_printf("Error.\n");
		exit(84);
	} else if (sig_num == SIGPIPE) {
		my_printf("Error.\n");
		exit(84);
	}
}
