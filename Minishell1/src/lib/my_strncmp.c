/*
** EPITECH PROJECT, 2017
** my_strncmp
** File description:
** .c
*/

#include "minishell.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (i < n && s1[i] == s2[i] && s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}
