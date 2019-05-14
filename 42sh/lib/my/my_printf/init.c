/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** database for printf
*/

#include "../../../include/my.h"

void func_init_next(tab_t *print)
{
	print[9].c = 'b';
	print[9].fptr = &my_putnbr_binary;
	print[10].c = 'S';
	print[10].fptr = &my_put_str_non_printable;
	print[11].c = 'p';
	print[11].fptr = &my_put_pointer_adress;
	print[12].c = 'f';
	print[12].fptr = &my_put_float;
}

void func_init_specifiers(spec_t *spec)
{
	spec[0].c = '0';
	spec[0].fptr = &spec_zero;
	spec[1].c = ' ';
	spec[1].fptr = &spec_space;
	spec[2].c = '+';
	spec[2].fptr = &spec_plus;
	spec[3].c = '-';
	spec[3].fptr = &spec_minus;
	spec[4].c = '#';
	spec[4].fptr = &spec_hashtag;
}

void func_init(tab_t *print, spec_t *spec)
{
	print[0].c = 'c';
	print[0].fptr = &my_put_char;
	print[1].c = 'd';
	print[1].fptr = &my_put_int;
	print[2].c = 'i';
	print[2].fptr = &my_put_int;
	print[3].c = 's';
	print[3].fptr = &my_put_str;
	print[4].c = '%';
	print[4].fptr = &my_put_ampersand;
	print[5].c = 'u';
	print[5].fptr = &my_put_unsigned_int;
	print[6].c = 'X';
	print[6].fptr = &my_putnbr_hexa;
	print[7].c = 'o';
	print[7].fptr = &my_putnbr_octal;
	print[8].c = 'x';
	print[8].fptr = &my_putnbr_hexa_lowcase;
	func_init_next(print);
	func_init_specifiers(spec);
}
