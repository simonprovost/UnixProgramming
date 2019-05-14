/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** my_clean_str
*/

#include <stdlib.h>

int count_correct_chars(char *str)
{
	int res = 0;
	int encounter = 0;

	for (int i = 0; str[i]; i++) {
		if ((str[i] != ' ' && str[i] != '\t')
		|| ((str[i] == ' ' || str[i] == '\t') && encounter == 1
		&& str[i + 1] != ' ' && str[i + 1] != '\t'
		&& str[i + 1] != 0)) {
			encounter = 1;
			res += 1;
		}
	}
	return (res);
}

void fill_clean_str(char *str, char *new_str)
{
	int j = 0;
	int encounter = 0;

	for (int i = 0; str[i]; i++) {
		if ((str[i] != ' ' && str[i] != '\t')
		|| ((str[i] == ' ' || str[i] == '\t') && encounter == 1
		&& str[i + 1] != ' ' && str[i + 1] != '\t'
		&& str[i + 1] != 0)) {
			new_str[j] = str[i];
			j++;
			encounter = 1;
		}
	}
	new_str[j] = 0;
}

char *my_clean_str(char *str)
{
	char *new_str = NULL;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * count_correct_chars(str) + 1);
	fill_clean_str(str, new_str);
	return (new_str);
}