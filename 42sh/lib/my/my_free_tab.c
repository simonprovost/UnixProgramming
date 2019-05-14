/*
** EPITECH PROJECT, 2017
** int_to_str
** File description:
** int_to_str made by Sanchez Lucas
*/

#include <stdlib.h>

void my_free_tab(char **tab)
{
	if (!tab)
		return;
	for (int i = 0; tab[i]; i++)
		free(tab[i]);
	free(tab);
}