/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void check_without_cd(info_shell_t *info_shell)
{
	if ((my_strncmp(info_shell->line, "../", 3) == 0) ||
	(my_strcmp(info_shell->line, "..") == 0))
		info_shell->line = my_strcat("cd ", info_shell->line);
}