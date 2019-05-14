/*
** EPITECH PROJECT, 2017
** PSU_42sh_2017
** File description:
** add_lvar.c
*/

#include "my.h"
#include "42sh.h"

int replace_lvar(char *name, char *value, ll_lvar_t *lvar)
{
	for (ll_lvar_t *tmp = lvar->next; tmp; tmp = tmp->next) {
		if (strcmp(tmp->name, name) == 0) {
			free(tmp->value);
			tmp->value = malloc(sizeof(char) * strlen(value) + 1);
			strcpy(tmp->value, value);
			return (1);
		}
	}
	return (0);
}

void create_lvar(char *name, char *value, ll_lvar_t *lvar)
{
	ll_lvar_t *n = malloc(sizeof(*n));
	ll_lvar_t *tmp = lvar;

	if (replace_lvar(name, value, lvar) == 1)
		return;
	n->next = NULL;
	n->name = malloc(sizeof(char) * strlen(name) + 1);
	n->value = malloc(sizeof(char) * strlen(value) + 1);
	strcpy(n->name, name);
	strcpy(n->value, value);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = n;
}

void add_valid_lvar(ll_lvar_t *lvar, char **str, int i, int *ret_value)
{
	if (there_is_a_equal(str[i]) == 1) {
		if (check_too_deep(get_lvar_two(str[i])) == 1) {
			printf("Directory stack not that deep.\n");
			*ret_value = 1;
			return;
		}
		create_lvar(get_lvar_one(str[i]), get_lvar_two(str[i]), lvar);
	} else
		create_lvar(get_lvar_one(str[i]), " ", lvar);
}

void set_func(char **str, shell_t shell, int *ret_value)
{
	if (my_tablen(str) == 1) {
		print_lvar(shell.local_var);
		return;
	}
	for (int i = 1; i < my_tablen(str); i++) {
		if (begin_with_letter(str[i]) == 1) {
			add_valid_lvar(shell.local_var, str, i, ret_value);
		} else {
			printf("%s: Variable name must begin with a letter.\n",
									str[0]);
			*ret_value = 1;
			break;
		}
	}
}