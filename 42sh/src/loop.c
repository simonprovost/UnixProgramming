/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

void my_signals(void)
{
	signal(SIGINT, sig_handler);
	signal(SIGSEGV, sig_handler);
	signal(SIGPIPE, sig_handler);
}

void my_loop(shell_t shell, int ret_value)
{
	char *str = NULL;

	global_env = shell.env;
	while (1) {
		my_signals();
		print_prompt(shell.env);
		str = get_next_line(stdin);
		if (str == NULL) {
			(isatty(STDIN_FILENO) ? my_printf("exit\n") : 0);
			free_list(shell.env);
			my_free_lla(shell.aliases);
			exit(ret_value);
		} else if (!str[0]) {
			free(str);
			continue;
		}
		ret_value = 0;
		parse_cmd(shell, str, &ret_value);
	}
}
