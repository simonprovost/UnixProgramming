/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int found_next(int *j, char *word, char *s, int i)
{
	if (s[i] == word[0]) {
		*j = i;
		return (found_next_next(j, word, s));
	}
	return (0);
}

int found_in_str(char *word, char *s)
{
	int j = 0;

	for (int i = 0 ; s[i] != '\0' ; i++) {
		if (found_next(&j, word, s, i) == 1)
			return (1);
	}
	return (0);
}