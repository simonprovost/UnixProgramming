/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** .h
*/

#include <stdarg.h>

#ifndef MY_H
#define MY_H

typedef struct myfunc_s {
	char balise;
	void (*my_func)();
} myfunc_t;

void my_putchar(char);
void my_put_nbr(int);
void my_putstr(char *);
int my_strlen(char *);
void my_put_nbr_base(int , char *);
void my_put_nbr_base_long(unsigned long , char *);
int my_getnbr(char const *);
int my_strlen_int(long long int);
int my_printf(char *, ...);
void check_balise(va_list arguments, char *str, int *i);
void my_func_charac(char *str, va_list arguments);
void my_func_number(char *str, va_list arguments);
void my_func_string(char *str, va_list arguments);
void my_func_string_captals(char *str, va_list arguments);
void my_func_dtoo(char *str, va_list arguments);
void my_func_utod(char *str, va_list arguments);
void my_func_dtox(char *str, va_list arguments);
void my_func_dtob(char *str, va_list arguments);
void my_func_dto_captalx(char *str, va_list arguments);
void my_func_ptoh(char *str, va_list arguments);
void my_func_percent(void);
void check_specifiers(char *tmp, va_list arguments, int check_zero);
void check_specifiers_string(char *tmp, va_list arguments, int check_zero);
void func_init_tab(myfunc_t *);
char *my_itoa(long long int, char[]);
void check_func_spec_point(char *, int *, va_list arguments, int *);
void my_calloc(char *tmp, char *str);
void check_spec_next(int *, char *, char *, int *);
void check_balise_next(int, int, char *, int *);
char *my_fill_string(char *, char *, int);
void check_hastag(char *, int *);
void begin_balise(char *, int *);
void show_double(float, int);
void my_func_float(char *, va_list);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char *src);
#endif
