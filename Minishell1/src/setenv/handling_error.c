/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

int check_info(char **my_info)
{
	for (int i = 0 ; my_info[1][i] != '\0' ; i++) {
		if ((INFO_I >= '0' && INFO_I <= '9' && INFO_I != '\0')
			|| (I_ERR >= '!' && I_ERR <= '/' && I_ERR != '\0'))
		return (1);
	}
	return (0);
}

int check_alpha_num(char *my_info)
{
	for (int i = 0 ; my_info[i] != '\0' ; i++) {
		if ((my_info[i] >= '!' && my_info[i] <= '/')
			&& ((my_info[0] >= 'A' && my_info[0] <= 'Z')
		|| (my_info[0] >= 'a' && my_info[0] <= 'z')))
		return (1);
	}
	return (0);
}
void handling_error(char **my_info, char *s, info_t *info, int check_who_is_it)
{
	char **check_alphanum = NULL;

	if (check_who_is_it == -84) {
		if (check_info(MF) == 1 &&
			fail_args_three(s, info, -84) != 84) {
			check_alphanum = str_to_word_array(s);
			check_alpha_num(check_alphanum[1]) == 1 ?
			my_printf(SETENV_ERR_ALPHA)
			: my_printf(SETENV_ERR);
		} else
			my_printf("setenv: Too many arguments.\n");
	}
}
