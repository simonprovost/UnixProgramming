/*
** EPITECH PROJECT, 2017
** int_to_str
** File description:
** int_to_str made by Sanchez Lucas
*/

#include <stdlib.h>

char *int_to_str(int nb)
{
	char *str;
	int i = 1;
	int j = 0;
	int tmp = nb;

	while (tmp > 9) {
		tmp /= 10;
		i++;
	}
	str = malloc(sizeof(char) * i + 1);
	j = i;
	while (i > 0) {
		str[i - 1] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	str[j] = '\0';
	return (str);
}
