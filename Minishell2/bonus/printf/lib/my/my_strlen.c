/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** .c
*/

int my_strlen(char *str)
{
	int count = 0;

	while (str[count] != '\0') {
		count++;
	}
	return (count);
}
