/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void print_file_or_folder_if_fail_cd(info_t *info)
{
	char *tmp = NULL;

	my_epur_str(info->s);
	tmp = info->s;
	for (int i = 3 ; tmp[i] != '\0' ; i++) {
		if (tmp[i] != '-' && tmp[i] != '\0')
			my_printf("%c", tmp[i]);
	}
}

void check_if_name_too_long(info_t *info, struct stat sb)
{
	if (my_strlen(info->s) > NAME_MAX)
		my_printf(": File name too long.\n");
	else {
		if (S_ISREG(sb.st_mode))
			my_printf(": Not a directory.\n");
		else
			my_printf(": No such file or directory.\n");
	}
}
