/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int my_str_isnum_remastered(char const *str)
{
	int i = 0;

	while (str[i] != 0) {
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int check_badly_next(char *s, int number, int letter)
{
	if ((letter > 0 && number > 0) || (letter > 0 && number > 0 &&
		s[5] == '-')
	|| (number == 1 && letter == 1 && s[5] == '-')) {
		my_printf("exit: Badly formed number.\n");
		return (1);
	}
	if ((number == 0 && letter > 0) || (s[5] == '-' && number == 0
		&& letter > 0)) {
		my_printf("exit: Expression Syntax.\n");
		return (1);
	}
	return (0);
}

int check_badly_number(char *s)
{
	int number = 0;
	int letter = 0;

	for (int i = 5 ; s[i] != '\0' ; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			number++;
		if ((s[i] >= 33 && s[i] <= 47) || (s[i] >= 58 && s[i] < 127))
			letter++;
	}
	return (check_badly_next(s, number, letter));
}

void badly_formed_func(char *s, int *check_badly)
{
	if (check_badly_number(s) == 1)
		*check_badly = 1;
}

void manage_exit(hashmap_t *hashmap, char *args, info_shell_t *info_shell)
{
	char **args_tab = str_to_word_array(args);
	int check_badly = 0;

	UNUSED(hashmap);
	if (!args_tab[1]) {
		isatty(0) ? my_printf("exit\n") : 0;
		exit (0);
	} else {
		badly_formed_func(args, &check_badly);
		if (check_badly != 0)
			return;
		if (my_str_isnum_remastered(args_tab[1]) == 0) {
			my_printf("exit: Expression Syntax.\n");
			return;
		}
		isatty(0) ? my_printf("exit\n") : 0;
		info_shell->return_value = my_getnbr(args_tab[1]);
		exit (my_getnbr(args_tab[1]));
	}
}