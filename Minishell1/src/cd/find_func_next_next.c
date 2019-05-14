/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char *fill_return_to_home(char *info)
{
	char *tmp = malloc(sizeof(char) * my_strlen(info) - 4);
	int x = 0;

	for (int i = 5 ; info[i] != '\0' ; i++) {
		tmp[x] = info[i];
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}

char *find_home_dirr(info_t *info)
{
	char *final_return = NULL;

	for (int i = 0 ; info->env[i] != NULL ; i++) {
		if (my_strncmp("HOME=", info->env[i], 4) == 0) {
			final_return = fill_return_to_home(info->env[i]);
			return (final_return);
		}
	}
	return (NULL);
}

char *fill_return_to_path(char *info)
{
	char *tmp = malloc(sizeof(char) * my_strlen(info) - 2);
	int x = 0;

	for (int i = 3 ; info[i] != '\0' ; i++) {
		tmp[x] = info[i];
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}

char *find_path_user(char *s)
{
	char *final_return = NULL;

	final_return = fill_return_to_path(s);
	return (final_return);
}

int found_next_next(int *j, char *word, char *s)
{
	for (int x = 0 ; x < my_strlen(word) ; x++) {
		if (s[*j] != word[x])
			return (1);
		*j += 1;
	}
	return (0);
}