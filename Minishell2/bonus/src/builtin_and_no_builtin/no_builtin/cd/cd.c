/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void check_if_name_too_long(char *path, struct stat sb,
info_shell_t *info_shell)
{
	if (my_strlen(path) > NAME_MAX) {
		my_printf(FILE_TOO_LONG);
		info_shell->return_value = 1;
	} else {
		if (S_ISREG(sb.st_mode) && S_ISDIR(sb.st_mode) == 0) {
			my_printf(": Not a directory.\n");
			info_shell->return_value = 1;
		} else {
			my_printf(": No such file or directory.\n");
			info_shell->return_value = 1;
		}
	}
}

void cd_only(hashmap_t *hashmap, info_shell_t *info_shell, struct stat sb,
char **args_line)
{
	char *directory = get_anything_value(hashmap, "HOME");
	char cwd[1024];
	char new_cwd[1024];

	if (stat(directory, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		info_shell->env = replace_case_hashmap(hashmap, "OLDPWD",
		getcwd(cwd, BUFF_SIZE) , info_shell->env);
		chdir(directory);
		info_shell->env = replace_case_hashmap(hashmap, "PWD",
		getcwd(new_cwd, BUFF_SIZE), info_shell->env);
	} else {
		my_printf("%s", args_line[1]);
		check_if_name_too_long(args_line[1], sb, info_shell);
	}
}

void cd_with_args(hashmap_t *hashmap, info_shell_t *info_shell, struct stat sb,
char **args_line)
{
	char cwd[1024];
	char new_cwd[1024];
	char *directory = my_strdup(args_line[1]);

	if (stat(directory, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		info_shell->my_old_pwd = my_strdup(getcwd(cwd, BUFF_SIZE));
		chdir(args_line[1]);
		info_shell->env = replace_case_hashmap(hashmap, "PWD",
		getcwd(new_cwd, BUFF_SIZE), info_shell->env);
	} else {
		my_printf("%s", args_line[1]);
		check_if_name_too_long(args_line[1], sb, info_shell);
	}
}

void cd_moins(hashmap_t *hashmap, info_shell_t *info_shell, struct stat sb,
char **args_line)
{
	char cwd[1024];
	char new_cwd[1024];
	char *old_dirr = getcwd(cwd, BUFF_SIZE);

	if (my_strcmp(info_shell->my_old_pwd,
	get_anything_value(hashmap, "PWD")) == 0) {
		my_printf(": No such file or directory.\n");
		info_shell->return_value = 1;
	} if (stat(info_shell->my_old_pwd, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		chdir(info_shell->my_old_pwd);
		info_shell->my_old_pwd = my_strdup(old_dirr);
		info_shell->env = replace_case_hashmap(hashmap, "PWD",
		getcwd(new_cwd, BUFF_SIZE), info_shell->env);
	} else {
		if (args_line[1][0] != '-' && args_line[1][0] != 0)
			my_printf("%s", args_line[1]);
		check_if_name_too_long(args_line[1], sb, info_shell);
	}
}

void manage_cd(hashmap_t *hashmap, char *args, info_shell_t *info_shell)
{
	char **args_line = str_to_word_array(args);
	struct stat sb;

	if (args_line[2]) {
		my_printf("cd: Too many arguments.\n");
		info_shell->return_value = 1;
		return;
	}
	if (!args_line[1]) {
		cd_only(hashmap, info_shell, sb, args_line);
		return;
	}
	if (args_line[1][0] == '-' && args_line[1][1] == 0)
		cd_moins(hashmap, info_shell, sb, args_line);
	else
		cd_with_args(hashmap, info_shell, sb, args_line);
}