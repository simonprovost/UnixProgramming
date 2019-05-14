/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "minishell.h"

void test_if_is_binary_and_can_run(char *line, info_shell_t *info_shell)
{
	int check = 0;

	if (!line)
		return;
	check = access(line, F_OK);
	if (check == 0) {
		proccess_if_file_exit(line,
		str_to_word_array(line), info_shell);
		info_shell->check_if_something_happened = 1;
	}
}

void test_with_dot_slash(info_shell_t *info_shell)
{
	if (info_shell->line[0] == '.' && info_shell->line[1] == '/')
		test_if_is_binary_and_can_run(info_shell->line, info_shell);
	else
		test_if_is_binary_and_can_run(
		my_strcat("./", info_shell->line), info_shell);
}

int proc_tab(info_shell_t *info_shell, int path_or_no,
char *args, char *tab_path)
{
	int check = 0;

	path_or_no == 0 ? check = access(tab_path, F_OK) :
	(check = access(my_key_copy(args, ' '), F_OK));
	if (check == 0) {
		path_or_no == 0 ? proccess_if_file_exit(tab_path,
		str_to_word_array(args), info_shell)
		: proccess_if_file_exit(my_key_copy(args, ' '),
		str_to_word_array(args), info_shell);
		info_shell->check_if_something_happened = 1;
		return (1);
	}
	return (0);
}

int begin_access_tab(char *args, char *path, info_shell_t *info_shell)
{
	if (!args || !path) {
		info_shell->return_value = 1;
		return (1);
	}
	my_epur_str(args);
	if (args[0] == '.' && args[1] == '/') {
		test_if_is_binary_and_can_run(args, info_shell);
		info_shell->return_value = 0;
		return (84);
	}
	return (0);
}

int test_access_with_tab(char *args, info_shell_t *info_shell, hashmap_t
*hashmap, int path_or_no)
{
	char *path = get_anything_value(hashmap, "PATH");
	char **tab_path = NULL;
	int check = -1;
	static int loop = 0;

	if (begin_access_tab(args, path, info_shell) != 0)
		return (info_shell->return_value);
	tab_path = fill_tab_with_userinput(path, my_key_copy(args, ' '));
	for (int i = 0 ; tab_path[i] ; i++) {
		if (proc_tab(info_shell, path_or_no, args, tab_path[i]) == 1) {
			check = 0;
			break;
		}
	}
	if (check == -1 && loop++ == 0)
		test_with_dot_slash(info_shell);
	loop = 0;
	if (info_shell->return_value != 0)
		return (84);
	return (0);
}