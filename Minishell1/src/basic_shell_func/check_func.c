/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

my_func_t func_tab[] =
{
	{"cd", change_dir},
	{"exit", exit_func},
	{"setenv", set_env_func},
	{"unsetenv", unset_env_func},
	{"env", env_print_func},
	{0, 0}
};

int check_strncmp_with_tab_func(char *dest, char *s)
{
	char *tmp = malloc(sizeof(char) * my_strlen(dest) + 1);
	int i = 0;

	if (my_strlen(s) < my_strlen(dest))
		return (1);
	for (; dest[i] != '\0'; i++)
		tmp[i] = s[i];
	tmp[i] = '\0';
	return (my_strncmp(dest, tmp, my_strlen(dest)));
}

void next_check_if_built_in(char *s, info_t *info, int j)
{
	if ((check_strncmp_with_tab_func(func_tab[j].balise, "setenv") == 0) ||
		(check_strncmp_with_tab_func(func_tab[j].balise, "unsetenv")
		== 0)) {
		info->check_if_some_things_happened = 1;
		func_tab[j].my_func(s, info->env, info);
	}
	else if (check_strncmp_with_tab_func(func_tab[j].balise, "env") == 0) {
		info->check_if_some_things_happened = 1;
		func_tab[j].my_func(s, info);
	}
	else {
		info->check_if_some_things_happened = 1;
		func_tab[j].my_func(s, info);
	}
}

int check_if_built_in(char *s, info_t *info)
{
	int j = 0;
	int check = 0;

	while (func_tab[j].balise != 0) {
		if (check_strncmp_with_tab_func(func_tab[j].balise, s) == 0) {
			next_check_if_built_in(s, info, j);
			check = 1;
		}
		j++;
	}
	return (check);
}

int check_if_empty(char *s)
{
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ' && s[i] != '\0')
			return (1);
	}
	return (0);
}

void test_if_you_have_access(info_t *info, char *final_path)
{
	int check_if_one = 0;
	int check_if_two = 0;

	for (int i = 1; i < info->size_path_array; i++)
	{
		final_path = new_path_test(info, final_path, i);
		next_access_func(final_path, info, &check_if_one);
		if (check_if_one == 1) {
			info->check_if_some_things_happened = 1;
			break;
		}
		(access(final_path, F_OK) == -1 && info->run_env == 0) ?
		(final_path = fill_path("./", info->info[0])) : 0;
		(access(final_path, F_OK) == 0) ?
		(show_programm_user(info, final_path, info->env), CFT = 1) : 0;
		if (check_if_two == 1) {
			info->check_if_some_things_happened = 1;
			break;
		}
	}
}
