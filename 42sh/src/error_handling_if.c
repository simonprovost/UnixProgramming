/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int is_if_error(char **s)
{
	if (!s[2])
		return (0);
	if (strcmp(s[2], ">") == 0 || strcmp(s[2], ">=") == 0 ||
	strcmp(s[2], "<") == 0 || strcmp(s[2], "<=") == 0 ||
	strcmp(s[2], "==") == 0 || strcmp(s[2], "!=") == 0)
		if (!s[1] || !s[3])
			return (1);
	return (0);
}

int check_expression(char **str)
{
	int pos = 0;

	if (!str)
		return (0);
	if (my_tablen(str) < 2)
		return (0);
	if (strcmp(str[1], "(") == 0 || strcmp(str[1], ")") == 0)
		pos += 1;
	if (!str[1 + pos])
		return (0);
	for (int i = 0 ; str[1 + pos][i] ; i++) {
		if ((str[1 + pos][i] < '0' || str[1 + pos][i] > '9')
		&& (str[1 + pos][i] != '(' && str[1 + pos][i] != ')'))
			return (1);
	}
	return (0);
}

int process_error_handlings(char *temp, char *tmp, int paren)
{
	if (too_few_args(tmp, paren) != 0 || missing_parenthesis(temp) != 0 ||
	expression_syntax_if(tmp) != 0 || empty_if(temp) != 0)
		return (1);
	return (0);
}

int check_error_handling_if(char **str)
{
	int paren = 0;
	char *tmp = delete_all_parenthese(str, &paren);
	char *temp = NULL;

	if (!tmp)
		return (84);
	temp = convert_tab_to_string(str);
	if (process_error_handlings(temp, tmp, paren) != 0)
		return (1);
	return (0);
}

int check_only_number(char **s, int *ret_if)
{
	if (strcmp(s[2], ">") == 0 || strcmp(s[2], ">=") == 0 ||
	strcmp(s[2], "<") == 0 || strcmp(s[2], "<=") == 0
	|| strcmp(s[2], "==") == 0 || strcmp(s[2], "!=") == 0)
		return (1);
	if (is_alpha_string(s[1]) == 0) {
		*ret_if = 2;
		return (0);
	}
	return (1);
}