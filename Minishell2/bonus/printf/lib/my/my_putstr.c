/*
** EPITECH PROJECT, 2017
** PSU_my_printf_2017
** File description:
** null
*/

#include "my.h"
#include <stdio.h>

void my_putstr(char *str)
{
	while (*str != '\0') {
		my_putchar(*str);
		str++;
	}
}
