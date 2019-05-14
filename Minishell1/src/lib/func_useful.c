/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *tm = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

	while (i < my_strlen(dest)) {
		tm[i] = dest[i];
		i++;
	}
	while (j < my_strlen(src)) {
		tm[i] = src[j];
		j++;
		i++;
	}
	tm[i] = '\0';
	return (tm);
}

void my_epur_str(char *my_str)
{
	char *read = my_str;
	char *str = my_str;
	int space = 1;

	while (*read != '\0') {
		if (*read != ' ' || !space)
			*str++ = *read;
		space = *read == ' ';
		read++;
	}
	if (space && str != my_str)
		str--;
	*str = '\0';
}

char *my_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *my_strdup_simple(char *str)
{
	char *copy = NULL;

	if (str != NULL) {
		copy = malloc(sizeof(char) * my_strlen(str) + 1);
		if (copy != NULL)
			return (my_strcpy(copy, str));
	}
	return (NULL);
}