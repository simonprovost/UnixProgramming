/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int too_few_args(char *tmp, int paren)
{
	char **tab_tmp = NULL;

	if (!tmp)
		return (1);
	tab_tmp = my_str_to_word_array(tmp, 32);
	if (my_tablen(tab_tmp) < 2 && paren == 0) {
		printf("if: Too few arguments.\n");
		free (tab_tmp);
		return (1);
	}
	return (0);
}

int empty_if(char *temp)
{
	char **tab_tmp = NULL;

	if (!temp)
		return (1);
	tab_tmp = my_str_to_word_array(temp, 32);
	for (int i = 0 ; temp[i] ; i++)
		if (temp[i] == '(' && temp[i + 1] && temp[i + 1] == ')') {
			printf("if: Empty if.\n");
			return (1);
		}
	if (tab_tmp && my_tablen(tab_tmp) < 3) {
		printf("if: Empty if.\n");
		return (1);
	}
	return (0);
}

int check_badly(char *str)
{
	int digit = 0;
	int alpha = 0;

	if (!str)
		return (84);
	for (int i = 0 ; str[i] ; i++) {
		if (isdigit(str[i]))
			digit++;
		else if (isalpha(str[i]))
			alpha++;
	}
	if (digit != 0 && alpha != 0)
		return (0);
	return (1);
}

int expression_syntax_if(char *tmp)
{
	char **tab_tmp = NULL;

	if (!tmp)
		return (1);
	tab_tmp = my_str_to_word_array(tmp, 32);
	if (is_if_error(tab_tmp) != 0 || check_expression(tab_tmp) != 0) {
		check_badly(tab_tmp[1]) != 0 ?
		printf("if: Expression Syntax.\n") :
		printf("if: Badly formed number.\n");
		return (1);
	}
	return (0);
}

int missing_parenthesis(char *temp)
{
	int paren_left = 0;
	int paren_right = 0;

	for (int i = 0 ; temp[i] ; i++) {
		if (temp[i] == 40)
			paren_left++;
		else if (temp[i] == 41)
			paren_right++;
	}
	if (paren_left != paren_right) {
		printf("Too many ('s.\n");
		return (1);
	}
	return (0);
}