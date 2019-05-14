/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

char *get_dir(env_t *env)
{
	char *cur_dir = get_env(env, "PWD");
	char *home = get_env(env, "HOME");
	char *verif_home = NULL;
	int i = 0;

	if (cur_dir == NULL || home == NULL)
		return (NULL);
	for (i = 0; cur_dir[i] && home[i] && cur_dir[i] == home[i]; i++);
	verif_home = malloc(sizeof(char) * (i + 1));
	for (i = 0; cur_dir[i] && home[i] && cur_dir[i] == home[i]; i++)
		verif_home[i] = cur_dir[i];
	verif_home[i] = 0;
	if (my_strcmp(home, verif_home) == 0) {
		free(verif_home);
		return (my_strcat("~", cur_dir + i));
	}
	free(verif_home);
	return (my_strdup(cur_dir));
}

void print_prompt(env_t *env)
{
	char *dir = get_dir(env);
	char *user = get_env(env, "USER");

	if (dir == NULL) {
		dir = malloc(sizeof(char) * 4096);
		getcwd(dir, 4096);
	}
	if (isatty(STDIN_FILENO)) {
		if (user != NULL)
			my_printf("%s@", user);
		my_printf("%s> ", dir);
	}
	free(dir);
}
