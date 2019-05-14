/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"
#include <stdlib.h>

char* my_itoa(long long int i, char b[])
{
	char const digit_number[] = "0123456789";
	char* p = b;
	int shifter = 0;

	if (i < 0) {
		*p++ = '-';
		i *= -1;
	}
	shifter = i;
	do {
		++p;
		shifter = (shifter / 10);
	}while (shifter);
	*p = '\0';
	do {
		*--p = digit_number[i % 10];
		i = i / 10;
	}while(i);
	return (b);
}
