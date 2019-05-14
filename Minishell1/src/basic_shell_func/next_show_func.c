/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void  	check_what_is_the_error_msg(int my_errno)
{
	if (my_errno == 8)
		my_printf("Exec format error. Binary file not executable.\n");
	else if (my_errno == 13)
		my_printf("Permission denied.\n");
	else
		my_printf("error.\n");

}

void check_return(int check, info_t *info, int errno_return)
{
	if (check == -1) {
		my_printf("%s: ", info->s_save);
		check_what_is_the_error_msg(errno_return);
		exit (1);
	}
}

void show_programm_user(info_t *info, char *path, char *env[])
{
	pid_t pid;
	int status = 0;
	int return_exec = 0;

	if ((pid = fork()) == 0) {
		return_exec = execve(path, info->info, env);
		return_exec == -1 ? check_return(return_exec, info, errno) : 0;
	}
	if (pid > 0) {
		if (waitpid(pid, &status, 0) > 0)
			my_child(status);
	}
}

void show_getcwd(void)
{
	char cwd[1024];
	int check_home = find_home(cwd);

	if (getcwd(cwd, BUFF_SIZE) != NULL && check_home == 1) {
		my_printf("~");
		for (int i = getbackn(cwd) - 1; i < my_strlen(cwd) ; i++)
			my_printf("%c", cwd[i]);
		my_printf("> ");
	} else if (getcwd(cwd, BUFF_SIZE) != NULL && check_home == 0) {
		for (int i = 0 ; i < my_strlen(cwd) ; i++)
			my_printf("%c", cwd[i]);
		my_printf("> ");
	} else
		perror("GETCWD error.");
}

void show_host(char **env)
{
	int found_pos_host = found_host(env);

	for (int i = 5; i < my_strlen(env[found_pos_host]) ; i++)
		my_printf("%c", env[found_pos_host][i]);
	my_printf(":");
}
