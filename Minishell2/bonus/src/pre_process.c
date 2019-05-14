/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

char **fill_new_env(void)
{
	char **my_personnal_env = NULL;
	char *path = GENERAL_PATH;
	char *pwd = "PWD=";
	char *oldpwd = "OLDPWD=";
	char *home = "HOME=";

	my_personnal_env = malloc(sizeof(char *) * 5);
	my_personnal_env[0] = my_strdup(path);
	my_personnal_env[1] = my_strdup(pwd);
	my_personnal_env[2] = my_strdup(oldpwd);
	my_personnal_env[3] = my_strdup(home);
	my_personnal_env[4] = NULL;
	return (my_personnal_env);
}

void init_info_shell(info_shell_t *info_shell)
{
	info_shell->my_old_pwd = NULL;
	info_shell->line = NULL;
	info_shell->env = NULL;
	info_shell->check_if_something_happened = 0;
	info_shell->return_value = 0;
	info_shell->op_redirect = NULL;
	info_shell->args_redirect = NULL;
	info_shell->tree_args = NULL;
}

int pre_process_programm(char **env, hashmap_t **hashmap,
info_shell_t *info_shell)
{
	int check = 0;

	*hashmap = hm_create(64000);
	if (!*hashmap)
		return (84);
	init_info_shell(info_shell);
	if (!env || !env[0]) {
		info_shell->env = fill_new_env();
		check = 1;
	}
	if ((*hashmap = fill_hashmap_with_env(*hashmap, check == 0 ? env :
	info_shell->env)) == NULL)
		return (84);
	if (check != 1 &&
	((info_shell->env = fill_env_with_hashmap(*hashmap, env)) == NULL))
		return (84);
	if (isatty(0))
		show_getcwd();
	info_shell->line = get_next_line(0);
	return (0);
}