/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int is_alpha_string(char *str)
{
	if (!str)
		return (1);
	for (int i = 0 ; str[i] ; i++) {
		if (isdigit(str[i]) == 0)
			return (1);
	}
	return (0);
}

int check_error_handling_repeat(char **str)
{
	if (my_tablen(str) < 3) {
		printf("repeat: Too few arguments.\n");
		return (1);
	}
	if (atoi(str[1]) >= INT_MAX || atoi(str[1]) < 0) {
		return (2);
	}
	if (is_alpha_string(str[1]) == 1) {
		printf("repeat: Badly formed number.\n");
		return (1);
	}
	return (0);
}

char **add_special_tab(char **tab, int user_choice)
{
	char **tmp = calloc(0, sizeof(char *) * (my_tablen(tab) + 1));
	int j = 0;

	for (int i = user_choice ; tab[i] ; i++)
		tmp[j++] = strdup(tab[i]);
	tmp[j] = NULL;
	return (tmp);
}

int process_repeat(char **str, env_t *env)
{
	int user_loop = atoi(str[1]);
	int ret_value_cmd = 0;

	for (int i = 0 ; i != user_loop ; i++) {
		my_exec(str + 2, env, (int[2]){0, 1});
	}
	return (ret_value_cmd);
}

void repeat_func(char **str, shell_t shell, int *ret_value)
{
	int ret = 0;

	if (!str) {
		*ret_value = 1;
		return;
	}
	if ((ret = check_error_handling_repeat(str)) != 0) {
		ret != 2 ? *ret_value = 1 : 0;
		return;
	}
	if (str[0] && str[1] && process_repeat(str, shell.env) != 0) {
		*ret_value = 1;
		return;
	}
}
