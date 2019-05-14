/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** create_lvar.c
*/

#include "my.h"
#include "42sh.h"

ll_lvar_t *init_lvar(void)
{
	ll_lvar_t *varl = malloc(sizeof(*varl));

	varl->name = NULL;
	varl->value = NULL;
	varl->next = NULL;
	return (varl);
}

char *get_lvar_one(char *str)
{
	char *one = malloc(sizeof(char) * strlen(str) + 1);
	int i = 0;

	while (str[i] != '=' && str[i]) {
		one[i] = str[i];
		i++;
	}
	one[i] = 0;
	return (one);
}

char *get_lvar_two(char *str)
{
	char *two = malloc(sizeof(char) * strlen(str) + 1);
	int i = 0;
	int a = 0;

	while (str[i] != '=' && str[i])
		i++;
	i++;
	while (str[i]) {
		two[a] = str[i];
		i++;
		a++;
	}
	two[a] = 0;
	return (two);
}

int valid_lvar(char *str)
{
	char **str_tab = NULL;
	int equal = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == '=')
			equal = 1;
	}
	if (equal == 0)
		return (0);
	str_tab = my_str_to_word_array(str, '=');
	(void)str_tab;
	return (1);
}

void print_lvar(ll_lvar_t *lvar)
{
	sort_lvar(lvar);
	for (ll_lvar_t *tmp = lvar->next; tmp; tmp = tmp->next) {
		my_printf("%s\t%s\n", tmp->name, tmp->value);
	}
}