/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int check_badly_next(char *s, int number, int letter, int *check_happened)
{
	if ((letter > 0 && number > 0) || (letter > 0 && number > 0 &&
		s[5] == '-')
	|| (number == 1 && letter == 1 && s[5] == '-')) {
		my_printf("exit: Badly formed number.\n");
		*check_happened = 1;
		return (1);
	}
	if ((number == 0 && letter > 0) || (s[5] == '-' && number == 0
		&& letter > 0)) {
		my_printf("exit: Expression Syntax.\n");
		*check_happened = 1;
		return (1);
	}
	return (0);
}

int check_badly_number(char *s, int *check_happened)
{
	int number = 0;
	int letter = 0;

	for (int i = 5 ; s[i] != '\0' ; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			number++;
		if ((s[i] >= 33 && s[i] <= 47) || (s[i] >= 58 && s[i] < 127))
			letter++;
	}
	return (check_badly_next(s, number, letter, check_happened));
}
