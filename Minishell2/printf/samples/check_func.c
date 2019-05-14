/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** null
*/

#include "my.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

myfunc_t g_tab[] =
{
	{'c', my_func_charac},
	{'d', my_func_number},
	{'i', my_func_number},
	{'s', my_func_string},
	{'S', my_func_string_captals},
	{'u', my_func_utod},
	{'o', my_func_dtoo},
	{'x', my_func_dtox},
	{'b', my_func_dtob},
	{'X', my_func_dto_captalx},
	{'p', my_func_ptoh},
	{'%', my_func_percent},
	{'f', my_func_float},
	{'F', my_func_float},
	{0, 0}
};

void change_size(int *size, char *str, int *i, va_list arguments)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
	int j = 0;
	(*size) = 0;

	my_calloc(tmp, str);
	while (str[*i] >= '0' && str[*i] <= '9') {
		tmp[j] = str[*i];
		j++;
		(*i)++;
	}
	tmp[j] = '\0';
	if (j != 0) {
		(*size) = my_getnbr(tmp);
		if ((str[*i] == 'd'))
			check_func_spec_point(str, i, arguments, size);
	}
	free(tmp);
}

int check_spec_plus(char *str, int *i, int *size, va_list arguments)
{
	int check_zero = 0;

	if (str[*i] == '.') {
		(*i)++;
		change_size(size, str, i, arguments);
	}
	if (str[*i] == '0')
		check_zero = 1;
	if (str[*i] == '+') {
		my_putchar('+');
		(*i)++;
	}
	return (check_zero);
}

void check_spec(char *str, int *size, int *i, va_list arguments)
{
	int k = 0;
	int check_zero = check_spec_plus(str, i, size, arguments);
	char *tmp = malloc(sizeof(char) * my_strlen(str) + 1);

	my_calloc(tmp, str);
	check_spec_next(&k, tmp, str, i);
	tmp[k] = '\0';
	if (k != 0 && (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u'
	|| str[*i] == 'x' || str[*i] == 'X'))
			check_specifiers(tmp, arguments, check_zero);
	if (k != 0 && (str[*i] == 's'))
			check_specifiers_string(tmp, arguments, check_zero);
	free(tmp);
}

void point_specifiers(int size, int *check_point, va_list arguments, char *str)
{
	va_list new_arguments;
	va_copy(new_arguments, arguments);
	char *tmp = va_arg(new_arguments, char *);
	int count = 0;
	char *final_number;

	if (size != 0) {
		final_number = malloc(sizeof(char) * my_strlen(tmp) + 1);
		my_calloc(final_number, str);
		while (count < size) {
			final_number[count] = tmp[count];
			count++;
		}
		final_number[count] = '\0';
		(*check_point) = 1;
		my_putstr(final_number);
		str++;
	}
	free(final_number);
}
void check_balise(va_list arguments, char *str, int *i)
{
	int j = 0;
	int size = 0;
	int check_point = 0;
	int g_tab_found = 0;
	va_list temporary_list;

	begin_balise(str, i);
	va_copy(temporary_list, arguments);
	check_spec(str, &size, i, arguments);
	if (size != 0)
		point_specifiers(size, &check_point, arguments, str);
	while (g_tab[j].balise != 0 || g_tab[j].balise == str[(*i)]) {
		if (g_tab[j].balise == str[(*i)] && check_point == 0) {
			g_tab[j].my_func(str + (*i), arguments);
			g_tab_found = 1;
		}
		j++;
	}
	check_balise_next(g_tab_found, size, str, i);
	va_end(temporary_list);
}