/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "../../include/my.h"

char *convert_tab_to_string(char **tab)
{
	char *result = strdup(tab[0]);
	char *tmp = NULL;
	char *tmp_result = NULL;

	for (int i = 1; tab[i]; i++) {
		tmp = my_strcat(" ", tab[i]);
		if (result) {
			tmp_result = strdup(result);
			free (result);
			result = my_strcat(tmp_result, tmp);
			free (tmp_result);
		} else
			result = strdup(tmp);
		free (tmp);
	}
	return (result);
}