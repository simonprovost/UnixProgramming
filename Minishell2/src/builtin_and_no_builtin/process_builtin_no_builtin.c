/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int proccess_if_file_exit(char *path, char **args_line,
info_shell_t *info_shell)
{
	pid_t pid = fork();
	int status = 0;

	if (pid == 0) {
		if ((execve(path, args_line, info_shell->env)) == -1) {
			check_return(args_line[0], errno, info_shell);
			info_shell->return_value = 1;
			exit (info_shell->return_value);
		}
	} else
		if (waitpid(pid, &status, 0) > 0)
			verif_signal(status, info_shell);
	if (info_shell->return_value == 139 || info_shell->return_value == 136
	|| info_shell->return_value == 1 || status / 256 > 0) {
		status / 256 > 0 ? info_shell->return_value = status / 256 : 0;
		return (84);
	}
	return (0);
}

int process_builtin(hashmap_t *hashmap, char *args, info_shell_t *info_shell)
{
	int path_or_no = 0;

	if (!args || args[0] == 0
	|| !info_shell->env || !info_shell->env[0])
		return (0);
	my_epur_str(args);
	if (args[0] == '/')
		path_or_no = 1;
	if ((test_access_with_tab(args, info_shell, hashmap, path_or_no))
	!= 0)
		return (info_shell->return_value);
	return (0);

}

void print_correct_file_error(char *s)
{
	for (int j = 0; my_strlen(s) != 0 && s[j] != '\0'; j++) {
		if (s[j] == ' ')
			break;
		my_printf("%c", s[j]);
	}
}

void not_found_error(info_shell_t *info_shell)
{
	print_correct_file_error(info_shell->line);
	my_printf(": Command not found.\n");
	info_shell->return_value = 1;
	info_shell->check_if_something_happened = 0;
}

int process_builtin_no_builtin(hashmap_t *hashmap, info_shell_t *info_shell)
{
	if (info_shell->line != NULL)
		my_epur_str(info_shell->line);
	if (info_shell->check_if_something_happened == 0)
		if ((process_no_builtin(hashmap, info_shell->line, info_shell))
		== 84) {
			info_shell->check_if_something_happened = 0;
			return (info_shell->return_value);
		}
	if (info_shell->check_if_something_happened == 0)
		if ((process_builtin(hashmap, info_shell->line, info_shell))
		!= 0)
			return (info_shell->return_value);
	if (info_shell->check_if_something_happened == 0 &&
	info_shell->line[0] != 0) {
		not_found_error(info_shell);
		return (0);
	}
	info_shell->return_value = 0;
	info_shell->check_if_something_happened = 0;
	return (0);
}