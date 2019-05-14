/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include <stdlib.h>

int my_strlen(char *);

int find_height(char **str)
{
	int i = 0;

	while (str[i] != NULL)
		i++;
}

char **my_strdup_2d_array(char **str)
{
	int height = find_height(str);
	char **tab_array = malloc(sizeof(char *) * (height + 1));
	int j = 0;
	int i = 0;

	for (i = 0; i < height; i++) {
		tab_array[i] = malloc(sizeof(char) * (my_strlen(str[i] + 1)));
		for (j = 0; str[i][j] != 0; j++)
			tab_array[i][j] = str[i][j];
		tab_array[i][j] = 0;
	}
	tab_array[i] = NULL;
	return (tab_array);
}
