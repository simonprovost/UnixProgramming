/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int is_malformed(char *str)
{
	int b = 0;
	int a = 0;
	int i = 0;

	if (str && str[0] == '-')
		a = 1;
	while (str[i]) {
		if (str[i] < 48 || str[i] > 57)
			b = 1;
		i++;
	}
	if ((str[1] < 48 || str[1] > 57) && str[1] != 0 && a == 1 && b == 1)
		return (1);
	return (0);
}

int str_is_num(char *str)
{
	int i = 0;
	int a = 0;
	int b = 0;
	int c = 0;

	if (str[0] == '-' && str[1] == 0)
		return (1);
	while (str[i]) {
		if ((str[i] < 48 || str[i] > 57) && str[i] != '-')
			a = 1;
		else
			b = 1;
		i++;
	}
	c = (str[0] == '-' ? 1 : 0);
	if (a == 1 && b == 1 && str[c] > 47 && str[c] < 58)
		return (2);
	else if (a == 1)
		return (1);
	return (0);
}

void exec_exit(int ret_value, shell_t shell)
{
	if (isatty(STDIN_FILENO))
		my_printf("exit\n");
	free_list(shell.env);
	my_free_lla(shell.aliases);
	exit(ret_value);
}

void exit_func(char **str, shell_t shell, int *ret_value)
{
	if (my_tablen(str) == 1)
		exec_exit(0, shell);
	if (my_tablen(str) == 2 && is_malformed(str[1]) == 1) {
		my_printf("exit: Malformed file inquiry.\n");
		*ret_value = 1;
		return;
	} else if (str_is_num(str[1]) == 1 || my_tablen(str) > 2) {
		my_printf("exit: Expression Syntax.\n");
		*ret_value = 1;
		return;
	} else if (str_is_num(str[1]) == 2) {
		my_printf("exit: Badly formed number.\n");
		*ret_value = 1;
		return;
	}
	exec_exit(my_getnbr(str[1]), shell);
}
