/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** too_deep.c
*/

#include "my.h"
#include "42sh.h"

int there_is_a_equal(char *str)
{
	for (int i = 0; i < (int)strlen(str); i++) {
		if (str[i] == '=')
			return (1);
	}
	return (0);
}

int begin_with_letter(char *str)
{
	char invalid[18] = "()[]=@+-%123456789";

	for (int j = 0; j < 18; j++) {
		if (str[0] == invalid[j])
			return (0);
	}
	return (1);
}

int is_int(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int check_too_deep(char *str)
{
	int i = 1;
	int letter = 0;

	if (str[0] != '=')
		return (0);
	while (str[i] != 0) {
		if (is_int(str[i]) == 0)
			letter = 1;
		i++;
	}
	if (letter == 0)
		return (1);
	else
		return (0);
}