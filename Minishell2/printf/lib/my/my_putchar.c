/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}
