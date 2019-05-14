/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** PSU_tetris_2017 made by Sanchez Lucas
*/

int chars_in_tab(char **tab)
{
	int len_tab = 0;

	for (int i = 0 ; tab[i] ; i++)
		for (int j = 0 ; tab[i][j] ; j++)
			len_tab++;
	return (len_tab);
}

int my_tablen(char **str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
