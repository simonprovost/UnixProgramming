/*
** EPITECH PROJECT, 2017
** my_minishell
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char *my_strncpy_setenv(char *dest, char *src, int n)
{
	int i = 0;

	while (src[i] && i < n) {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}

int check_s(char c)
{
	if (c <= ' ' || c >= 127 || c == 10 || c == 9)
		return (0);
	return (1);
}

int count_word_setenv(char *str)
{
	int i = 0;
	int word = 0;

	while (str != NULL && str[i]) {
		if (check_s(str[i]) == 1 &&
		check_s(str[i + 1]) == 0)
			word++;
		i++;
	}
	return (word);
}

char **init_tab_malloc_setenv(char *str)
{
	char **tab = NULL;

	if (!str)
		return (NULL);
	if ((tab = malloc((count_word_setenv(str) + 1) * sizeof(char *)))
	== NULL)
		return (NULL);
	return (tab);
}

char **split_setenv(char *str)
{
	int j = 0;
	int i = 0;
	char **tab = NULL;
	int len = 0;

	if ((tab = init_tab_malloc_setenv(str)) == NULL)
		return (NULL);
	while (str != NULL && str[i]) {
		if (check_s(str[i]))
			len++;
		if (check_s(str[i]) == 1 && check_s(str[i + 1]) == 0) {
			tab[j] = malloc(len + 1);
			my_strncpy_setenv(tab[j], &str[i - len + 1], len);
			len = 0;
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	return (tab);
}