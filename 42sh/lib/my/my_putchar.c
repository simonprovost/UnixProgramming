/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** putchar to appeal
*/

void write(int fd, char *c, int n);

int my_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
