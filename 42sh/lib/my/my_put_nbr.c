/*
** EPITECH PROJECT, 2017
** my put nbr
** File description:
** put nbr
*/

void my_putchar(char);

int my_int_limit(void)
{
	my_putchar('-');
	my_putchar('2');
	my_putchar('1');
	my_putchar('4');
	my_putchar('7');
	my_putchar('4');
	my_putchar('8');
	my_putchar('3');
	my_putchar('6');
	my_putchar('4');
	my_putchar('8');
	return (0);
}

int my_put_nbr(int nb)
{
	int mod;

	if (nb == -2147483648) {
		my_int_limit();
		return (0);
	}
	if (nb < 0) {
		my_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0) {
		if (nb >= 10) {
			mod = (nb % 10);
			nb = (nb - mod) / 10;
			my_put_nbr(nb);
			my_putchar(48 + mod);
		} else
			my_putchar(48 + nb % 10);
	}
	return (0);
}
