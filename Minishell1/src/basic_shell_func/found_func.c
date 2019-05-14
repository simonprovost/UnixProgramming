/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int found_env(char **env)
{
	int check = 84;

	for (int j = 0 ; env[j] != NULL ; j++) {
		if (my_strncmp(env[j], "PATH=", 4) == 0) {
			check = j;
			break;
		}
	}
	return (check);
}

int found_host(char **env)
{
	int j = 0;

	for (int i = 0 ; env[j] != NULL ; i++) {
		if (i == my_strlen(env[j])) {
			j++;
			i = 0;
		}
		if (my_strncmp(env[j], "HOST=", 3) == 0) {
			return (j);
		}
	}
	return (84);
}

int next_find_home(char *cwd)
{
	for (int i = 0; cwd[i] != '\0'; i++) {
		if (C1 && C2 && C3 && C4)
			return (1);
	}
	return (0);
}

int find_home(char *cwd)
{
	if (getcwd(cwd, BUFF_SIZE) != NULL) {
		if (next_find_home(cwd) == 1)
			return (1);
	}
	return (0);
}

void found_size_path_array(info_t *info)
{
	for (; info->path[info->size_path_array] != NULL ; I_SPA += 1);
}