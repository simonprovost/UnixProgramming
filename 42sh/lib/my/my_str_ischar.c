/*
** EPITECH PROJECT, 2017
** my put nbr
** File description:
** put nbr
*/

int my_str_ischar(char *str, char c)
{
	for (int i = 0; str[i]; i++) {
		if (str[i] != c)
			return (0);
	}
	return (1);
}