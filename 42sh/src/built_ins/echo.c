/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** echo
*/

#include "42sh.h"

void process_args_echo(char **str, int pos_last_flag)
{
	for (int i = pos_last_flag ; str[i] ; i++) {
		if (str[i]) {
			my_printf("%s", str[i]);
			(str[i + 1] != NULL ? write(1, " ", 1) : 0);
		}
	}
}

void detect_flag(int *pos_flag, int *flag_n, char **str)
{
	if (my_tablen(str) > 1) {
		if (strcmp(str[1], "-n") == 0) {
			*pos_flag += 1;
			*flag_n += 1;
		}
	}
}

void echo_func(char **str, __attribute__((unused))shell_t shell, int *ret_value)
{
	int pos_flag = 0;
	int flag_n = 0;

	if (!str) {
		*ret_value = 84;
		return;
	} else if (str && !str[1]) {
		my_printf("\n");
		*ret_value = 0;
		return;
	}
	detect_flag(&pos_flag, &flag_n, str);
	process_args_echo(str, pos_flag + 1);
	flag_n == 0 ? write(1, "\n", 1) : 0;
}