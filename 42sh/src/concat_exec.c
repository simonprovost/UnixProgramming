/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int test_exec(char *test_access)
{
	if (access(test_access, X_OK) == 0)
		return (1);
	return (0);
}

char **get_path(env_t *env)
{
	char **path = my_str_to_word_array(get_env(env, "PATH"), ':');

	if (!path)
		path = my_str_to_word_array(
		"/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",
		':');
	return (path);
}

char *concat_exec(char **str, env_t *env)
{
	char **path = get_path(env);
	char *test_access = NULL;
	char *concat = NULL;
	int i = 0;

	if (!str || !str[0] || !str[0][0])
		return (0);
	while (path[i] != NULL) {
		concat = my_strcat("/", str[0]);
		test_access = my_strcat(path[i], concat);
		free(concat);
		if (test_exec(test_access) == 1) {
			my_free_tab(path);
			return (test_access);
		}
		i++;
		free(test_access);
	}
	my_free_tab(path);
	return (NULL);
}
