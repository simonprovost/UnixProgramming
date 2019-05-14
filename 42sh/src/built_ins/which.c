/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** which
*/

#include "42sh.h"

int print_first_path(env_t *env, char *str)
{
	char **path = my_str_to_word_array(get_env(env, "PATH"), ':');
	char *test_access = NULL;
	char *concat = NULL;
	int i = 0;

	if (!path || !str)
		return (0);
	for (; path[i] != NULL; i++) {
		concat = my_strcat("/", str);
		test_access = my_strcat(path[i], concat);
		free(concat);
		if (!access(test_access, X_OK)) {
			printf("%s\n", test_access);
			return (0);
		}
		free(test_access);
	}
	my_free_tab(path);
	return (1);
}

void which_func(char **str, shell_t shell, int *ret_value)
{
	if (my_tablen(str) < 2) {
		*ret_value = 1;
		printf("which: Too few arguments.\n");
		return;
	}
	for (int i = 1; str[i]; i++) {
		if (is_a_built_in(str[i]) && strcmp(str[i], "env")) {
			printf("%s: shell built-in command.\n", str[i]);
			continue;
		}
		if (print_first_path(shell.env, str[i])
		&& !is_a_built_in(str[i])) {
			printf("%s: Command not found.\n", str[i]);
			*ret_value = 1;
		}
	}
}