/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

int error_handling_redi_left(char *file_name_tmp, info_shell_t *info_shell)
{
	if (!file_name_tmp || file_name_tmp[0] == 0) {
		dup2(info_shell->fd_fileno[0], 0);
		dup2(info_shell->fd_fileno[1], 1);
		my_printf(MISSING_NAME);
		info_shell->return_value = 1;
		return (1);
	}
	return (0);
}

int manage_left(binary_tree_t *tree, info_shell_t *info_shell,
hashmap_t *hashmap, int fd_out)
{
	int fd = 0;
	struct stat sb;
	char *file_name_tmp = my_strdup(!info_shell->file_name ? NULL :
	info_shell->file_name);

	if (error_handling_redi_left(file_name_tmp, info_shell) == 1)
		return (info_shell->return_value);
	tree->operator != DRL ? my_epur_str(file_name_tmp) : 0;
	if ((fd = open(file_name_tmp, O_RDONLY)) == -1) {
		my_printf("%s", file_name_tmp);
		check_if_name_too_long(file_name_tmp, sb, info_shell);
		info_shell->return_value = 1;
		info_shell->error = 1;
		return (info_shell->return_value);
	}
	dup2(fd, 0);
	close(fd);
	proccess_exec_node(tree->tleft, info_shell, hashmap, fd_out);
	return (0);
}

int read_inf(binary_tree_t *tree, info_shell_t *info_shell)
{
	char *s = NULL;
	int fd = open("tmp_04239912213", O_CREAT | O_TRUNC | O_WRONLY, 0644);

	if (fd < 0) {
		info_shell->return_value = 1;
		return (info_shell->return_value);
	}
	isatty(0) ? write(1, "? ", 2) : 0;
	while ((s = get_next_line(0))) {
		if (!my_strcmp(tree->tright->args, s))
			break;
		else
			write(fd, s, my_strlen(s));
		write(fd, "\n", 1);
		isatty(0) ? write(1, "? ", 2) : 0;
		free(s);
	}
	free(s);
	close(fd);
	return (0);
}

int manage_double_left_redirection(binary_tree_t *tree,
info_shell_t *info_shell, hashmap_t *hashmap, int fd_out)
{
	my_epur_str(tree->tright->args);
	if (read_inf(tree, info_shell) != 0)
		return (info_shell->return_value);
	info_shell->file_name = my_strdup("tmp_04239912213");
	manage_left(tree, info_shell, hashmap, fd_out);
	return (0);
}
