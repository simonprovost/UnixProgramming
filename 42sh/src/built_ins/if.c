/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int process_if(char **str, shell_t shell);

int check_if(char **s, int *ret_if)
{
	int ret = 0;

	if (check_only_number(s, ret_if) == 0)
		return (1);
	if (!s[2] || !s[1] || !s[3])
		return (0);
	strcmp(s[2], ">") == 0 && strcmp(s[1], s[3]) > 0 ? ret = 1 : 0;
	strcmp(s[2], ">=") == 0 && strcmp(s[1], s[3]) >= 0 ? ret = 1 : 0;
	strcmp(s[2], "<") == 0 && strcmp(s[1], s[3]) < 0 ? ret = 1 : 0;
	strcmp(s[2], "<=") == 0 && strcmp(s[1], s[3]) <= 0 ? ret = 1 : 0;
	strcmp(s[2], "==") == 0 && strcmp(s[1], s[3]) == 0 ? ret = 1 : 0;
	strcmp(s[2], "!=") == 0 && strcmp(s[1], s[3]) != 0 ? ret = 1 : 0;
	*ret_if = 4;
	return (ret);
}

int process_if(char **str, shell_t shell)
{
	int ret_value = 0;
	int ret_if = 0;
	char *tmp = NULL;

	if (check_if(str, &ret_if) != 1) {
		if (check_then_if(str, shell) != 0)
			return (1);
		return (0);
	}
	if (check_then_if(str, shell) != 0)
		return (1);
	tmp = convert_tab_to_string(str + ret_if);
	tmp = my_clean_str(tmp);
	check_then(str) != 0 && str[ret_if] != NULL ?
	parse_cmd(shell, tmp, &ret_value) : 0;
	return (ret_value);
}

void if_func(char **str, shell_t shell, int *ret_value)
{
	if (!str) {
		*ret_value = 1;
		return;
	}
	if (check_error_handling_if(str) != 0) {
		*ret_value = 1;
		return;
	}
	if (parse_if(str) != 0) {
		*ret_value = 1;
		return;
	}
	if (process_if(str, shell) != 0) {
		*ret_value = 0;
		return;
	}
	(void)shell;
}