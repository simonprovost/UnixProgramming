/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

void exec_cd_minus(env_t *env, int *ret_value, char *old_pwd, char *cur_dir)
{
	if (old_pwd == NULL || chdir(old_pwd) == -1) {
		old_pwd != NULL ? my_putstr(old_pwd) : 0;
		my_printf(": No such file or directory.\n");
		*ret_value = 1;
		free(cur_dir);
		return;
	}
	old_pwd = my_strdup(cur_dir);
	change_pwd(env);
}

void exec_cd(env_t *env, char **str, int *ret_value)
{
	char *cur_dir = malloc(sizeof(char) * 4096);
	static char *old_pwd = NULL;

	getcwd(cur_dir, 4096);
	if (my_strcmp(str[1], "-") == 0)
		exec_cd_minus(env, ret_value, old_pwd, cur_dir);
	else if (chdir(str[1]) == -1) {
		if (access(str[1], F_OK) == -1 || strlen(str[1]) > NAME_MAX) {
			strlen(str[1]) > N_MAX ? printf(FILE_TOO_LONG, str[1])
			: printf("%s: No such file or directory.\n", str[1]);
		} else
			my_printf("%s: Not a directory.\n", str[1]);
		*ret_value = 1;
	} else {
		old_pwd = my_strdup(cur_dir);
		change_pwd(env);
	}
	free(cur_dir);
}

void cd_func(char **str, shell_t shell, int *ret_value)
{
	char *home = get_env(shell.env, "HOME");

	if (str[1] == NULL) {
		if (home == NULL) {
			my_printf("cd: No home directory\n");
			*ret_value = 1;
			return;
		}
		chdir(home);
		change_pwd(shell.env);
	} else if (str[2] != NULL) {
		my_printf("cd: Too many arguments.\n");
		*ret_value = 1;
	} else
		exec_cd(shell.env, str, ret_value);
}
