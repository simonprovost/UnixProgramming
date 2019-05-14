/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int is_parenthese(char *str)
{
	if (!str)
		return (01);
	for (int i = 0 ; str[i] ; i++) {
		if (str[i] == '(' || str[i] == ')')
			return (1);
	}
	return (0);
}

int check_pos_parenthesis(int *decrease, char **str)
{
	for (int i = 0 ; str[i] ; i++)
		if (is_parenthese(str[i]) == 1) {
			strcmp(str[i], "(") == 0 ? *decrease += 1 : 0;
			break;
		}
	for (int i = my_tablen(str) - 1 ; i >= 0 ; i--)
		if (is_parenthese(str[i]) == 1) {
			strcmp(str[i], ")") == 0 ? *decrease += 1 : 0;
			break;
		}
	return (*decrease != 0 ? 1 : 0);
}

int decrease_parenthesis(char **str)
{
	int decrease = 0;

	for (int i = 0 ; str[i] ; i++) {
		if (check_pos_parenthesis(&decrease, str) != 0)
			return (decrease);
	}
	return (decrease);
}

int count_loop_foreach(char **str)
{
	int decrease = decrease_parenthesis(str);

	return (my_tablen(str) - 2 - decrease);
}

int count_parenthesis(char **str)
{
	int count = 0;

	for (int i = 0 ; str[i] ; i++)
		if (is_parenthese(str[i]) == 1)
			count++;
	return (count);
}