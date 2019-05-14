/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

/*
** BONUS
** show_host(env);
*/
void show_hos_and_dirr(char **env)
{
	UNUSED(env);
	show_getcwd();
}

void print_correct_file_error(char *s)
{
	for (int j = 0; my_strlen(s) != 0 && s[j] != '\0'; j++) {
		if (s[j] == ' ')
			break;
		my_printf("%c", s[j]);
	}
}