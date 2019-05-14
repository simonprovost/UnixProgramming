/*
** EPITECH PROJECT, 2017
** my str is num
** File description:
** my str is num
*/

#include <ctype.h>

int my_str_is_alphanum(char *str)
{
	if (!str)
		return (1);
	for (int i = 0 ; str[i] ; i++) {
		if (isalnum(str[i]) == 0)
			return (0);
	}
	return (1);
}

int my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != 0) {
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
