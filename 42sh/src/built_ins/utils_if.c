/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

void clean_parenthesis(char **str)
{
	if (*str == NULL) {
		return;
	}
	for (int i = 0 ; (*str)[i] ; i++) {
		if ((*str)[i] == ')' || (*str)[i] == '(')
			(*str)[i] = ' ';
	}
	my_clean_str(*str);
}

int empty_string(char *str)
{
	if (!str)
		return (1);
	for (int i = 0 ; str[i] ; i++) {
		if (str[i] != 32)
			return (1);
	}
	return (0);
}

int my_memmove(char **s1, char **s2)
{
	if (s1 && s2) {
		memset(*s1, 0, sizeof(char) * strlen(*s1));
		*s1 = strdup(*s2);
		memset(*s2, 0, sizeof(char) * strlen(*s2));

	} else
		return (1);
	return (0);
}

char **clean_tab(char **str)
{
	if (!str)
		return (NULL);
	for (int i = 0 ; str[i] ; i++) {
		str[i] = my_clean_str(str[i]);
	}
	return (str);
}

char **set_null_empty_case_tab(char **str)
{
	for (int i = 0 ; str[i] ; i++) {
		if (empty_string(str[i]) == 0) {
			str[i] = NULL;
		}
	}
	return (str);
}