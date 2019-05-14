/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include <stdio.h>
#include "minishell.h"

void begin_loop_shell(int i, info_shell_t *info_shell, int fd_out)
{
	if (i == 1) {
		info_shell->fd_fileno[0] = dup(0);
		info_shell->fd_fileno[1] = fd_out;
	}
	info_shell->check_if_something_happened = 0;
}

void re_init_and_prompt(info_shell_t *info_shell)
{
	dup2(info_shell->fd_fileno[0], 0);
	dup2(info_shell->fd_fileno[1], 1);
	if (isatty(0))
		show_getcwd();
}

void free_each_loop(info_shell_t *info_shell)
{
	free (info_shell->line);
	destroy_binary_tree(info_shell->tree_args);
	info_shell->tree_args = NULL;
	info_shell->line = (get_next_line(0));
}

int loop_shell(hashmap_t *hashmap, info_shell_t *info_shell)
{
	static int i = 0;
	int fd_out = dup(1);

	i++;
	begin_loop_shell(i, info_shell, fd_out);
	if (count_op(info_shell->line) != 0)
		if (process_redirection(info_shell, hashmap, fd_out) == 84)
			return (84);
	if (count_op(info_shell->line) == 0)
		if (process_builtin_no_builtin(hashmap, info_shell) == 84)
			return (84);
	re_init_and_prompt(info_shell);
	free_each_loop(info_shell);
	if (!info_shell->line || info_shell->line[0] == 12) {
		isatty(0) ? my_printf("\nexit") : 0;
		return (1);
	}
	info_shell->return_value = 0;
	return (0);
}

int main(__attribute__((unused))int ac,
__attribute__((unused))char **av, char **env)
{
	hashmap_t *hashmap = NULL;
	info_shell_t *info_shell = malloc(sizeof(*info_shell));
	int loop_check = 0;
	int return_value = 0;

	if ((pre_process_programm(env, &hashmap, info_shell)) == 84)
		return (84);
	while (info_shell->line != NULL) {
		loop_check = loop_shell(hashmap, info_shell);
		if (loop_check == 84)
			return (84);
		else if (loop_check == 1) {
			return_value = info_shell->return_value;
			return (return_value);
		}
	}
	isatty(0) ? my_printf("\nexit\n") : 0;
	return_value = info_shell->return_value;
	free_all(info_shell->env, hashmap);
	return (return_value);
}