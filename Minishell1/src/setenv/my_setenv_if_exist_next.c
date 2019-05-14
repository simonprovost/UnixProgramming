/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int check_if_fail_args_setenv(char *s, info_t *info)
{
	int check_word = 0;

	for (int i = 0 ; s[i] != '\0' ; i++) {
		if (s[i] == ' ')
			check_word++;
	}
	info->count_args = check_word;
	return (check_word >= 3 ? 84 : 0);
}

int fail_args_three(char *s, info_t *info, int check_who_is_it)
{
	int check_word = 0;

	for (int i = 0 ; s[i] != '\0' && check_who_is_it == -84 ; i++) {
		if (s[i] == ' ')
			check_word++;
	}
	info->count_args = check_word;
	return (check_word >= 3 ? 84 : 0);
}

char **malloc_setenv(char **env, char **new_env, char **info_rec, info_t *i)
{
	int j = 0;

	for (; env[j] != NULL ; j++)
		new_env[j] = malloc(sizeof(char *) * my_strlen(env[j]));
	(i->count_args >= 2) ?
	(new_env[j] = malloc(sizeof(char *) * my_strlen(info_rec[1]) +
	my_strlen(info_rec[2]) + 1)) :
	(new_env[j] = malloc(sizeof(char *) * my_strlen(info_rec[1]) + 1));
	new_env[j][0] = '=';
	return (new_env);
}

int detect_who_is_it_setenv(info_t *info, char **my_info)
{
	for (int i = 0 ; info->env[i] != NULL ; i++) {
		if (my_strncmp(info->env[i], my_info[1],
			my_strlen(my_info[1])) == i) {
			return (i);
		}
	}
	return (-84);
}