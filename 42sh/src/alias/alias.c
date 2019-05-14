/*
** EPITECH PROJECT, 2017
** alias42sh
** File description:
** alias.c
*/

#include "42sh.h"
#include "my.h"

int		check_name_exist(ll_alias_t *lla, char *name, char *alias)
{
	for (ll_alias_t *tmp = lla->next; tmp; tmp = tmp->next) {
		if (strcmp(tmp->name, name) == 0) {
			free(tmp->alias);
			tmp->alias = malloc(sizeof(char) * strlen(alias) + 1);
			strcpy(tmp->alias, alias);
			write_alias(lla);
			return (1);
		}
	}
	return (0);
}

void 		alias_func(char **str, shell_t shell, int *ret_value)
{
	char *str_alias = NULL;

	(void)shell;
	(void)ret_value;
	if (my_tablen(str) > 3) {
		str_alias = get_str_alias(str);
		add_alias(str[1], str_alias, shell.aliases, 1);
	} else if (my_tablen(str) == 3) {
		add_alias(str[1], str[2], shell.aliases, 0);
	} else if (my_tablen(str) == 1) {
		sort_lla(shell.aliases);
		print_alias(shell.aliases);
	}

}

char **process_replace_alias(char **str, ll_alias_t *lla, int *loop)
{
	ll_alias_t *tmp = lla->next;
	int ret = 0;

	for (; tmp && (strcmp(str[0], tmp->name)
	|| !tmp->name); tmp = tmp->next);
	if (!tmp)
		return (str);
	if (alias_loop(tmp, lla) == 1) {
		printf("Alias loop.\n");
		*loop = 1;
		return (str);
	} else if (alias_loop(tmp, lla) == 2)
		return (str);
	while (alias_is_another(tmp->alias, lla)) {
		tmp = step_up_alias(tmp->alias, lla, &ret);
		if (ret == -1)
			return (str);
	}
	return (my_strtab_cat(my_str_to_word_array(tmp->alias, ' '), str));
}

int replace_alias(btree_t *tree, ll_alias_t *lla)
{
	char **cmd = NULL;
	int loop = 0;

	if (tree->left)
		if (replace_alias(tree->left, lla))
			return (1);
	if (tree->right)
		if (replace_alias(tree->right, lla))
			return (1);
	if (!tree->cmd)
		return (0);
	cmd = my_str_to_word_array(tree->cmd, ' ');
	cmd = process_replace_alias(cmd, lla, &loop);
	if (loop == 1)
		return (1);
	free(tree->cmd);
	tree->cmd = convert_tab_to_string(cmd);
	my_free_tab(cmd);
	return (0);
}