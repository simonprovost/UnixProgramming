/*
** EPITECH PROJECT, 2017
** null
** File description:
** null
*/

#include "minishell.h"

void badly_formed_func(char *s, int *check_happened, int *check_badly)
{
	if (check_badly_number(s, check_happened) == 1)
		*check_badly = 1;
}

char *fill_final_return_exit(char *final, char *s, int rest)
{
	int x = 0;
	int i = rest + 1;

	for (; s[i] != '\0'; i++) {
		final[x] = s[i];
		x++;
	}
	final[x] = '\0';
	return (final);
}

void free_exit_func_one_args(char *final, char *s, info_t *info)
{
	free(final);
	free(s);
	free(global_env);
	free(info);
}

void exit_func_one_args(char *s, info_t *info)
{
	int j = 0;
	int rest = 0;
	char *final = NULL;
	int final_path = 0;
	int check_badly = 0;
	int check_happened = 0;

	for (; s[j] != ' ' ; j++);
	rest = j;
	j++;
	badly_formed_func(s, &check_happened, &check_badly);
	if (check_badly == 0) {
		if (check_happened == 0)
			my_printf("exit\n");
		final = malloc(sizeof(char) * (j - rest + 2));
		final = fill_final_return_exit(final, s, rest);
		final_path = my_getnbr(final);
		free_exit_func_one_args(final, s, info);
		exit (final_path);
	}
}

void check_args_exit(char *s, int check_args, info_t *info)
{
	if (check_args == 1)
		exit_func_one_args(s, info);
	else {
		my_printf("exit\n");
		free(s);
		free(global_env);
		free(info);
		exit(0);
	}
}
