/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void next_getbackn(char *str, int *i)
{
	if (str[*i + 4] != '\0') {
		*i += 5;
		for (; str[*i] != 47 ; *i += 1);
		str[*i] == 47 ? *i += 1 : 0;
	}
}

int getbackn(char *str)
{
	int check_backn = 0;
	int i = 0;

	for (; str[i] != '\0' ; i++) {
		if (str[i] == 'h' && str[i + 1] == 'o' &&
			str[i + 2] == 'm' && str[i + 3] == 'e') {
			next_getbackn(str, &i);
			return (i);
		}
	}
	return (check_backn);
}

int next_find_home(char *cwd)
{
	for (int i = 0; cwd[i] != '\0'; i++) {
		if (C1 && C2 && C3 && C4)
			return (1);
	}
	return (0);
}

int find_home(char *cwd)
{
	if (getcwd(cwd, BUFF_SIZE) != NULL) {
		if (next_find_home(cwd) == 1)
			return (1);
	}
	return (0);
}

void show_getcwd(void)
{
	char cwd[1024];
	int check_home = find_home(cwd);

	if (getcwd(cwd, BUFF_SIZE) != NULL && check_home == 1) {
		my_printf("~");
		for (int i = getbackn(cwd) - 1; i < my_strlen(cwd) ; i++)
			my_printf("%c", cwd[i]);
		my_printf("> ");
	} else if (getcwd(cwd, BUFF_SIZE) != NULL && check_home == 0) {
		for (int i = 0 ; i < my_strlen(cwd) ; i++)
			my_printf("%c", cwd[i]);
		my_printf("> ");
	} else
		perror("GETCWD error.");
}