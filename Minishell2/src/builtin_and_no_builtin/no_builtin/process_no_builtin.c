/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

my_func_t func_tab[] =
{
	{"cd", manage_cd},
	{"exit", manage_exit},
	{"setenv", manage_setenv},
	{"unsetenv", manage_unsetenv},
	{"env", manage_env},
	{0, 0}
};

int is_builtin(char *line)
{
	for (int j = 0 ; func_tab[j].balise != 0 ; j++) {
		if (my_strcmp(func_tab[j].balise,
		my_key_copy(line, ' ')) == 0) {
			return (1);
		}
	}
	return (0);
}

int process_no_builtin(hashmap_t *hashmap, char *line, info_shell_t *info_shell)
{
	if (!line)
		return (info_shell->return_value);
	my_epur_str(line);
	if (!info_shell->env || !line || !hashmap)
		return (1);
	for (int j = 0 ; func_tab[j].balise != 0 ; j++) {
		if (my_strcmp(func_tab[j].balise,
		my_key_copy(line, ' ')) == 0) {
			func_tab[j].my_func(hashmap, line, info_shell);
			info_shell->check_if_something_happened = 1;
		}
	}
	if (info_shell->return_value != 0)
		return (84);
	return (0);
}