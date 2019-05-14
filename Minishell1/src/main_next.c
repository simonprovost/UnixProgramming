/*
** EPITECH PROJECT, 2017
** null
** File description:
** null
*/

#include "minishell.h"


void check_tty(char **env)
{
	if (isatty(0))
		show_hos_and_dirr(env);
}

void sig_handler(int signo)
{
	if (signo == SIGINT) {
		my_printf("\n");
		check_tty(global_env);
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

void loop_main(char *s, info_t *info, char *final_path)
{
	if (my_strlen(s) != 0 && check_if_empty(s) == 1 && my_strlen(s) != 0)
		analyse_user_input(info, s, final_path);
	if (info->check_if_some_things_happened == 0 && my_strlen(s) != 0 &&
		s[0] != ' ' && check_if_empty(s) != 0) {
		print_correct_file_error(s);
		my_printf(": Command not found.\n");
	}
	info->check_if_some_things_happened = 0;
}

void begin_programm(info_t *info, int argc, char **env)
{
	fill_begin_info(info, argc, env);
	check_env(info);
	check_signal();
}
