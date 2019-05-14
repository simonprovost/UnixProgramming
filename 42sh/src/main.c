/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2017
** File description:
** PSU_minishell1_2017 made by Sanchez Lucas
*/

#include "42sh.h"

int main(int ac, char **av, char **envp)
{
	ll_alias_t *lla = init_lla();
	ll_lvar_t *lvar = init_lvar();
	env_t *my_env = NULL;
	shell_t shell = {.env = my_env, .aliases = lla, .local_var = lvar};
	int ret = 0;

	(void) av;
	if (ac != 1)
		return (84);
	if (verif_env(envp) == 0)
		my_env = fill_my_env(my_env);
	else
		my_env = create_list(envp);
	shell.env = my_env;
	my_loop(shell, ret);
	return (0);
}
