/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void check_few_args(int count_args, info_t *info)
{
	if (count_args > 2) {
		info->check_if_some_things_happened = 1;
		my_printf("cd: Too many arguments.\n");
	}
}

void check_cd_moin(info_t *info, struct stat sb, char *s, int count_args)
{
	int pos_old = 0;
	char **my_s = str_to_word_array(s);

	if (count_args == 2) {
		if (my_strncmp(my_s[1], "-", 1) == 0) {
			pos_old = func_to_found_old(info);
			old_pwd_with_only_path(info, pos_old);
			cd_moin(sb, info, s);
			info->check_if_some_things_happened = 1;
		}
	}
	info->check_if_some_things_happened = 1;
}

void check_if_args(int count_args, char *s, struct stat sb, info_t *info)
{
	if (count_args <= 2 && count_args != 1 && s[3] != '-') {
		info->check_if_some_things_happened = 1;
		cd_with_args(sb, info, s);
	}
}

void check_if_cd_only(int count_args, char *dir, struct stat sb, info_t *info)
{
	if (count_args == 1) {
		info->check_if_some_things_happened = 1;
		cd_only(sb, info, dir, info->s);
	}
}

int check_s(char *s)
{
	if (my_strlen(s) == 2)
		return (0);
	return (1);
}