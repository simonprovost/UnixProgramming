/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "../../include/my.h"

void print_tab(char **tab)
{
	if (!tab)
		return;
	for (int i = 0 ; tab[i] ; i++) {
		printf("%s\n", tab[i]);
	}
}