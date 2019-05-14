/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char **fill_new_env(char **my_personnal_env)
{
	char *path = GENERAL_PATH;
	char *pwd = "PWD=";
	char *oldpwd = "OLDPWD=";
	char *home = "HOME=";

	my_personnal_env = malloc(sizeof(char *) * 5);
	my_personnal_env[0] = malloc(sizeof(char *) * my_strlen(path));
	my_personnal_env[1] = malloc(sizeof(char *) * my_strlen(pwd));
	my_personnal_env[2] = malloc(sizeof(char *) * my_strlen(oldpwd));
	my_personnal_env[3] = malloc(sizeof(char *) * my_strlen(home));
	my_personnal_env[0] = path;
	my_personnal_env[1] = pwd;
	my_personnal_env[2] = oldpwd;
	my_personnal_env[3] = home;
	my_personnal_env[4] = NULL;
	return (my_personnal_env);
}

void check_env(info_t *info)
{
	int pos_path = 0;
	char **my_personnal_env = NULL;

	if (info->env[0] == NULL) {
		my_personnal_env = fill_new_env(my_personnal_env);
		info->env = my_personnal_env;
		info->check_env_not_found = 1;
	}
	pos_path = found_env(info->env);
	info->pos_path = pos_path;
}
