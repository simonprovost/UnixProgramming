/*
** EPITECH PROJECT, 2017
** my_exec_2017
** File description:
** DESCRIPTION
*/

#include "minishell.h"

char **global_env;

void free_all(char *s, info_t *info)
{
	free(global_env);
	free(s);
	free(info->info);
	free(info->path);
	free(info->env);
	free(info->my_old_pwd);
	free(info->my_current_pwd);
}

char *pre_loop(info_t *info, char *s)
{
	global_env = info->env;
	check_tty(info->env);
	s = get_next_line(0);
	return (s);
}

void loop_s_not_null(char *s, info_t *info, char *final_path)
{
	my_epur_str(s);
	loop_main(s, info, final_path);
	info->check_if_some_things_happened = 0;
}

int main(int argc, char *argv[], char *env[])
{
	info_t *info = malloc(sizeof(info_t));
	char *s = NULL;
	int end = 0;
	char *final_path = NULL;
	UNUSED(argv);

	begin_programm(info, argc, env);
	while (!end && info->pos_path != 84) {
		s = pre_loop(info, s);
		if (s == NULL || s[0] == 12) {
			isatty(0) ? my_printf("exit\n") : 0;
			return (0);
		} else if (s != NULL)
			loop_s_not_null(s, info, final_path);
		else
			end = !end;
	}
	free_all(s, info);
	return (0);
}