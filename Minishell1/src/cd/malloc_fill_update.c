/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char **malloc_each_case_update(char **e, char **nv, info_t *info)
{
	int i = 0;

	for (int j = 0 ; e[j] != NULL ; j++) {
		if (j != info->pos_old && j != info->pos_current) {
			nv[i] = malloc(sizeof(char *) * my_strlen(e[j]));
			i++;
		}
		if (j == info->pos_old && j != info->pos_current) {
			nv[i] = malloc(sizeof(char *) *
			my_strlen(info->my_old_pwd) + 7);
			i++;
		}
		if (j == info->pos_current && j != info->pos_old) {
			nv[i] = malloc(sizeof(char *) *
			my_strlen(info->my_current_pwd) + 4);
			i++;
		}
	}
	nv[i] = '\0';
	return (nv);
}

char **fill_each_case_update(char **e, char **nv, info_t *info)
{
	int j = 0;
	int i = 0;
	char *tmp = NULL;
	char *tmp_2 = NULL;

	for (; e[j] != NULL ; j++) {
		(j != info->pos_old && j != info->pos_current) ?
		(nv[i] = e[j], i++) : 0;
		if (j == info->pos_old && j != info->pos_current){
			tmp = my_strcat("OLDPWD=", info->my_old_pwd);
			1 == 1 ? nv[i] = tmp, i++ : 0;
		}
		if (j == info->pos_current && j != info->pos_old) {
			tmp_2 = my_strcat("PWD=", info->my_current_pwd);
			1 == 1 ? nv[i] = tmp_2, i++ : 0;
		}
	}
	nv[i] = NULL;
	return (nv);
}

char **update_env(info_t *info)
{
	int size_len = (func_to_read_size(info));
	int pos_old = func_to_found_old(info);
	int pos_current = func_to_found_pwd(info);
	char **my_new_env = NULL;

	my_new_env = malloc(sizeof(char *) * (size_len + 2));
	info->pos_old = pos_old;
	info->pos_current = pos_current;
	my_new_env = malloc_each_case_update(info->env, my_new_env, info);
	my_new_env = fill_each_case_update(info->env, my_new_env, info);
	return (my_new_env);
}

void old_pwd_with_only_path(info_t *info, int pos_old)
{
	char *tmp = NULL;
	int x = 0;

	if (info->env[pos_old] != NULL) {
		tmp = malloc(sizeof(char) * (my_strlen(info->env[pos_old]) -
		my_strlen("OLDPWD=") + 1));
		for (int i = 7 ; info->env[pos_old][i] != '\0' ; i++) {
			tmp[x] = info->env[pos_old][i];
			x++;
		}
		tmp[x] = '\0';
		info->my_old_pwd = tmp;
	}
}
