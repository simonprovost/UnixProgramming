/*
** EPITECH PROJECT, 2017
** my str cat
** File description:
** concatenates two strings
*/

#include <stdlib.h>

int my_strlen(const char *str);

char *my_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	char *str =
	malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

	while (dest && dest[i]) {
		str[i] = dest[i];
		i++;
	}
	while (src && src[j]) {
		str[i] = src[j];
		j++;
		i++;
	}
	str[i] = 0;
	return (str);
}
