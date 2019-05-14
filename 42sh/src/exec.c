/*
** EPITECH PROJECT, 2018
** minishell1_2017
** File description:
** minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int exec_error_handling(char **str, env_t *env)
{
	if (!str || !str[0])
		return (1);
	if (access(str[0], F_OK) == 0
	&& (access(str[0], X_OK) == -1 || opendir(str[0]))
	&& !concat_exec(str, env)) {
		my_printf("%s: Permission denied.\n", str[0]);
		return (1);
	} else if (!concat_exec(str, env) && access(str[0], F_OK) == -1) {
		my_printf("%s: Command not found.\n", str[0]);
		return (1);
	}
	return (0);
}

void child_process(char **str, env_t *env, int input, int output)
{
	char *real_path = concat_exec(str, env);

	if (dup2(input, 0) == -1 || dup2(output, 1) == -1)
		exit(84);
	if (!real_path)
		real_path = str[0];
	if (execve(real_path, str, list_to_2d_arr(env)) == -1) {
		my_printf("%s: Exec format error. Wrong Architecture.\n",
									str[0]);
		exit(1);
	}
}

int my_exec(char **str, env_t *env, int *fd)
{
	int status = 0;
	int save[2];
	pid_t pid = 0;

	if ((save[0] = dup(0)) == -1)
		exit(84);
	if ((save[1] = dup(1)) == -1)
		exit(84);
	if (exec_error_handling(str, env))
		return (1);
	pid = fork();
	if (!pid)
		child_process(str, env, fd[0], fd[1]);
	waitpid(pid, &status, 0);
	close(fd[0]);
	close(fd[1]);
	if (dup2(save[0], 0) == -1 || dup2(save[1], 1) == -1) {
		exit(84);
	}
	return (check_segfault(status));
}
