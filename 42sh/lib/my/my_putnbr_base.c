/*
** EPITECH PROJECT, 2017
** my_putnbr_base
** File description:
** put nbr to base
*/

#include "../../include/my.h"

void my_putchar(char c);

void my_putnbr_base(int nb, char *b)
{
	(nb < 0 ? my_putchar('-'), nb *= -1 : 0);
	(nb > my_strlen(b) - 1 ? my_putnbr_base(nb / my_strlen(b), b) : 0);
	my_putchar(b[nb % my_strlen(b)]);
}
