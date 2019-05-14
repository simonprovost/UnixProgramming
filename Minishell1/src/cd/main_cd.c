/*
** EPITECH PROJECT, 2017
** PSU_minishell1_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

void cd_moin(struct stat sb, info_t *info, char *s)
{
	char cwd[1024];
	char new_cwd[1024];
	char *tmp = NULL;
	UNUSED(s);

	if (stat(info->my_old_pwd, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		tmp = getcwd(cwd, BUFF_SIZE);
		chdir(info->my_old_pwd);
		info->my_old_pwd = tmp;
		info->my_current_pwd = getcwd(new_cwd, BUFF_SIZE);
		info->env = update_env(info);
	} else {
		print_file_or_folder_if_fail_cd(info);
		check_if_name_too_long(info, sb);
	}
}

void cd_with_args(struct stat sb, info_t *info, char *s)
{
	char cwd[1024];
	char new_cwd[1024];

	if (stat(find_path_user(s), &sb) == 0 && S_ISDIR(sb.st_mode)) {
		info->my_old_pwd = getcwd(cwd, BUFF_SIZE);
		chdir(find_path_user(s));
		info->my_current_pwd = getcwd(new_cwd, BUFF_SIZE);
		info->env = update_env(info);
		info->check_if_some_things_happened = 1;

	} else {
		print_file_or_folder_if_fail_cd(info);
		check_if_name_too_long(info, sb);
	}
	info->check_if_some_things_happened = 1;
}

void cd_only(struct stat sb, info_t *info, char *directory, char *s)
{
	char cwd[1024];
	char new_cwd[1024];
	UNUSED(s);

	if (stat(directory, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		info->my_old_pwd = getcwd(cwd, BUFF_SIZE);
		chdir(directory);
		info->my_current_pwd = getcwd(new_cwd, BUFF_SIZE);
		info->env = update_env(info);
		info->check_if_some_things_happened = 1;

	} else {
		if (info->check_env_not_found != 1) {
			print_file_or_folder_if_fail_cd(info);
			check_if_name_too_long(info, sb);
		} else
			my_printf("cd: No home directory.\n");
	}
	info->check_if_some_things_happened = 1;
}

void change_dir(char *s, info_t *info)
{
	struct stat sb;
	int count_args = 0;
	char *directory = NULL;

	count_args = count_args_cd(s);
	directory = find_home_dirr(info);
	info->s = s;
	check_cd_moin(info, sb, s, count_args);
	check_if_args(count_args, s, sb, info);
	if (found_in_str("cd", s) == 0)
		check_if_cd_only(count_args, directory, sb, info);
	check_few_args(count_args, info);
	info->check_if_some_things_happened = 1;
}