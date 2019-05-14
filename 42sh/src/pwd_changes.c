/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** pwd_changes
*/

#include "42sh.h"

void replace_pwd(env_t *env, char *pwd)
{
	env = env->next;
	while (env && env->name && my_strcmp(env->name, "PWD") != 0)
		env = env->next;
	if (env == NULL)
		return;
	free(env->value);
	env->value = my_strdup(pwd);
}

void replace_old_pwd(env_t *env, char *pwd)
{
	env = env->next;
	while (env && env->name && my_strcmp(env->name, "OLDPWD") != 0)
		env = env->next;
	if (env == NULL)
		return;
	free(env->value);
	env->value = my_strdup(pwd);
}

void change_pwd(env_t *env)
{
	char *old_pwd = get_env(env, "PWD");
	char *new_pwd = malloc(sizeof(char) * 4096);

	getcwd(new_pwd, 4096);
	replace_old_pwd(env, old_pwd);
	replace_pwd(env, new_pwd);
	free(new_pwd);
}