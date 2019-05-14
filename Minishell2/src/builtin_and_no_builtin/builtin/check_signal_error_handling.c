/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char **fill_tab_with_userinput(char *path, char *line)
{
	char **tab = str_to_word_array(path);

	if (!tab || !line)
		return (NULL);
	for (int i = 0 ; tab[i] ; i++)
		tab[i] = my_strcat(tab[i], line[0] != '/' ?
		my_strcat("/", line) : line);
	return (tab);
}

void check_what_is_the_error_msg(int my_errno, info_shell_t *info_shell)
{
	if (my_errno == ENOEXEC) {
		my_printf("Exec format error. Binary file not executable.\n");
		info_shell->return_value = 1;
	} else if (my_errno == EACCES) {
		my_printf("Permission denied.\n");
		info_shell->return_value = 1;
	} else {
		my_printf("Exec format error. Wrong Architecture.\n");
		info_shell->return_value = 1;
	}
}

void check_return(char *line, int errno_return, info_shell_t *info_shell)
{
	my_printf("%s: ", line, info_shell->return_value);
	check_what_is_the_error_msg(errno_return, info_shell);
}

void verif_signal(int status, info_shell_t *info_shell)
{
	int check = 0;

	if (status >= 256)
		info_shell->return_value = 1;
	if (WTERMSIG(status) == SIGSEGV) {
		my_printf("Segmentation fault");
		check = 1;
		info_shell->return_value = 139;
	} else if (WTERMSIG(status) == SIGFPE) {
		my_printf("Floating exception");
		check = 1;
		info_shell->return_value = 136;
	}
	if (WCOREDUMP(status) && (info_shell->return_value == 139
	|| info_shell->return_value == 136))
		my_printf(" (core dumped)");
	(check == 1 ? my_putchar('\n') : 0);
}
