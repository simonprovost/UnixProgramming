/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"


char *my_key_copy(char *src, char separator)
{
	int i = 0;
	int j = 0;
	char *final = NULL;

	if (!src)
		return (NULL);
	for (; src[i] != 0 ; i++)
		if (src[i] == separator)
			break;
	if ((final = malloc(sizeof(char) * i + 1)) && !final)
		return (NULL);
	for (; j != i ; j++)
		final[j] = src[j];
	final[j] = 0;
	return (final);
}

char *my_value_copy(char *src, char separator)
{
	int i = 0;
	int value_separator = 0;
	char *final = NULL;
	int begin = 0;
	int active = 0;

	if (src == NULL)
		return (NULL);
	for (; src[i] != 0 ; i++)
		if (src[i] == separator && active == 0) {
			value_separator = i;
			active++;
		}
	value_separator++;
	final = malloc(sizeof(char) * (i - value_separator) + 1);
	for (int j = value_separator ; j != i ; j++)
		final[begin++] = src[j];
	final[begin] = 0;
	return (final);
}