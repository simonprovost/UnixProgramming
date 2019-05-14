/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

static const builtin_t built_ins[] =
{
	{"cd", &cd_func},
	{"exit", &exit_func},
	{"env", &env_func},
	{"setenv", &setenv_func},
	{"unsetenv", &unsetenv_func},
	{"echo", &echo_func},
	{"alias", &alias_func},
	{"unalias", &unalias_func},
	{"repeat", &repeat_func},
	{"if", &if_func},
	{"where", &where_func},
	{"which", &which_func},
	{"set", &set_func},
	{"unset", &unset_func},
	{"foreach", &foreach_func},
	{NULL, NULL}
};

void reset_fd(int *fd, int *save)
{
	close(fd[0]);
	close(fd[1]);
	if (dup2(save[0], 0) == -1)
		exit(84);
	if (dup2(save[1], 1) == -1)
		exit(84);
}

void process_dups(int *fd)
{
	if (dup2(fd[0], 0) == -1)
		exit(84);
	if (dup2(fd[1], 1) == -1)
		exit(84);
}

int is_a_built_in(char *str)
{
	for (int i = 0; built_ins[i].name; i++) {
		if (str && !my_strcmp(str, built_ins[i].name))
			return (1);
	}
	return (0);
}

int check_built_ins(char **str, shell_t shell, int *ret_value, int *fd)
{
	int save[2];

	if ((save[0] = dup(0)) == -1)
		exit(84);
	if ((save[1] = dup(1)) == -1)
		exit(84);
	for (int i = 0; built_ins[i].name; i++) {
		if (str && !my_strcmp(str[0], built_ins[i].name)) {
			process_dups(fd);
			built_ins[i].fptr(str, shell, ret_value);
			reset_fd(fd, save);
			return (0);
		}
	}
	return (1);
}
