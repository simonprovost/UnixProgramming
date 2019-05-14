/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int count_args_cd(char *s)
{
	int count = 0;

	for (int i = 0 ; s[i] != '\0' ; i++) {
		if (s[i] == ' ')
			count++;
	}
	return (count + 1);
}
