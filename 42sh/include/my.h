/*
** EPITECH PROJECT, 2017
** my h
** File description:
** all my headers
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <string.h>

typedef struct tab_s {
	char c;
	void (*fptr)(va_list);
} tab_t;

typedef struct spec_s {
	char c;
	int (*fptr)(va_list, int);
} spec_t;

void my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void func_init(tab_t *print, spec_t *spec);
void my_put_char(va_list);
void my_put_int(va_list);
void my_put_unsigned_int(va_list);
void my_put_str(va_list);
void my_put_ampersand(va_list);
void my_putnbr_hexa(va_list);
void my_putnbr_hexa_lowcase(va_list);
void my_putnbr_octal(va_list);
void my_putnbr_binary(va_list);
void my_putnbr_base(int, char *);
void my_putnbr_base_lowcase(long long, int);
void my_put_str_non_printable(va_list list);
int my_printf(char *, ...);
int my_str_isalpha(char *);
int my_str_isnum(char *);
int my_strcmp(char const *, char const *);
char *my_strdup(char *);
char *my_strcat(char *, char *);
int my_strncmp(char const *, char const *, int);
char **my_strdup_2d_array(char **);
void my_put_pointer_adress(va_list list);
int spec_zero(va_list, int);
int spec_dot(va_list, int);
int spec_space(va_list, int);
void my_put_float(va_list);
int spec_plus(va_list, int);
int spec_minus(va_list, int);
int spec_hashtag(va_list, int);
char **my_str_to_word_array(char *, char);
char *get_next_line(FILE *);
void my_free_tab(char **);
int my_tablen(char **);
char *my_clean_str(char *);

#endif   /* MY_H */
