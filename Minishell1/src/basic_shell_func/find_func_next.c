/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void next_getbackn(char *str, int *i)
{
	if (str[*i + 4] != '\0') {
		*i += 5;
		for (; str[*i] != 47 ; *i += 1);
		str[*i] == 47 ? *i += 1 : 0;
	}
}

int getbackn(char *str)
{
	int check_backn = 0;
	int i = 0;

	for (; str[i] != '\0' ; i++) {
		if (str[i] == 'h' && str[i + 1] == 'o' &&
			str[i + 2] == 'm' && str[i + 3] == 'e') {
			next_getbackn(str, &i);
			return (i);
		}
	}
	return (check_backn);
}
