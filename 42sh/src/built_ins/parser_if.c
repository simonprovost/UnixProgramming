/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int need_to_memmove(char **str)
{
	if (!str)
		return (84);
	for (int i = 0 ; str[i] ; i++) {
		if (empty_string(str[i]) == 0)
			return (1);
	}
	return (0);
}

int pos_empty_case(char **str)
{
	int i = 0;

	while (empty_string(str[i]) == 1) {
			i++;
		}
	return (i);
}

char **memmove_tab(char **str)
{
	int j = 0;

	if (need_to_memmove(str) == 0) {
		return (str);
	}
	for (int i = pos_empty_case(str) + 1 ; (str)[i] ; i++) {
		j = i;
		while (empty_string(str[i]) == 0)
			i++;
		if (my_memmove(&str[j - 1], &str[i]) != 0)
			break;
	}
	str = clean_tab(str);
	return (str);
}

int parse_if(char **str)
{
	if (!(str))
		return (84);
	for (int i = 0 ; (str)[i] ; i++) {
		if (is_parenthese((str)[i]) == 1) {
			clean_parenthesis(&str[i]);
		}
	}
	str = clean_tab(str);
	str = memmove_tab(str);
	return (0);
}