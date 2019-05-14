/*
** EPITECH PROJECT, 2018
** nukl
** File description:
** null
*/

#include "minishell.h"

void my_epur_str(char *my_str)
{
	char *read = my_str;
	char *str = my_str;
	int space = 1;

	while (*read) {
		if ((*read != ' ' && *read != 9) || (!space))
			(*read == 9) ? (*str++ = ' ') : (*str++ = *read);
		space = (*read == ' ' || *read == 9);
		read++;
	}
	if (space && str != my_str)
		str--;
	*str = '\0';
}