/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** .c
*/

#include <stdio.h>
#include <limits.h>

int my_getnbr(char const *str)
{
	int operator = 1;
	long number = 0;

	if (str[0] == '0') {
		str++;
	}
	while (*str == '-' || *str == '+') {
		operator = ((*str == '-') ? operator * -1 : operator);
		str++;
	}
	while (*str >= '0' && *str <= '9') {
		number = (number * 10) + (*str - '0');
		str++;
	}
	number = number * operator;
	return ((number >= INT_MAX || number <= INT_MIN) ? 84 : number);
}
