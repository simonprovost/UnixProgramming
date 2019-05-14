/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int init_right_management(binary_tree_t *tree, int *is_otrunc)
{
	if (!tree)
		return (1);
	if (tree->operator == DRR)
		*is_otrunc = 1;
	if (tree->tright->args)
		my_epur_str(tree->tright->args);
	return (0);
}

void error_handling_right_redi(binary_tree_t *tree, info_shell_t *info_shell)
{
	DIR *dir;

	my_printf("%s", tree->tright->args);
	if (my_strlen(tree->tright->args) > NAME_MAX)
		my_printf(FILE_TOO_LONG);
	else {
		dir = opendir(tree->tright->args);
		if (errno == EISDIR)
			my_printf(IS_A_DIRR);
		else if (execve(tree->tright->args,
		str_to_word_array(tree->tright->args), info_shell->env) == -1)
			errno == EACCES ? my_printf(P_DENIED) : 0;
	}
	info_shell->return_value = 1;
}

int manage_right(binary_tree_t *tree, info_shell_t *info_shell,
hashmap_t *hashmap, int fd_out)
{
	int is_otrunc = 0;
	int fd = 0;
	char *tmp_args = NULL;

	if (init_right_management(tree, &is_otrunc) != 0)
		return (info_shell->return_value);
	if ((fd = open(tree->tright->args, FLAG_RIGHT_REDI, 0644)) == -1) {
		error_handling_right_redi(tree, info_shell);
		info_shell->return_value = 1;
		return (info_shell->return_value);
	}
	if (tree->tleft->args)
		tmp_args = my_strdup(tree->tleft->args);
	else
		tmp_args = my_strdup("");
	proccess_exec_node(tree->tleft, info_shell, hashmap,
	is_builtin(my_key_copy(tmp_args, ' ')) == 1 ? fd_out : fd);
	return (0);
}
