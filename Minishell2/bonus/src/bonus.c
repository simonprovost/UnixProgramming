/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void sig_handler(int signo)
{
	if (signo == SIGINT) {
		my_printf("\n");
		isatty(0) ? show_getcwd() : 0;
	}
	if (signo == SIGPIPE) {
		my_printf("Caught signal SIGPIPE %d\n", signo);
		exit (84);
	}
	if (signo == SIGSEGV) {
		my_printf("Segmentation violation.\n");
		exit (84);
	}
	if (signo == SIGSYS) {
		my_printf("Bad system call.\n");
		exit (84);
	}
}

void check_signal(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGPIPE, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGSEGV, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
	if (signal(SIGSYS, sig_handler) == SIG_ERR) {
		perror("error.");
		exit (1);
	}
}

int before_loop(char **env, hashmap_t **hashmap,
info_shell_t *info_shell)
{
	if ((pre_process_programm(env, hashmap, info_shell)) == 84)
		return (84);
	check_signal();
	return (0);
}