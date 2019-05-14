/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

int my_strlen_int(long long int value)
{
	int count = 1;

	while (value > 9) {
		count++;
		value /= 10;
	}
	return (count);
}
