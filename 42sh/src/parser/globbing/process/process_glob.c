/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

int check_whereis_ref(char **tab , char *ref)
{
	for (int i = 0 ; tab[i] ; i++)
		if (strcmp(tab[i], ref) == 0)
			return (i);
	return (0);
}

void loop_glob(char **cmd, int retval, glob_t *paths,
error_var_t *int_value)
{
	char *ref = NULL;
	char **ref_tab = my_str_to_word_array(*cmd, 32);

	ref = parse_glob(*cmd, 2);
	if (retval == 0) {
		add_new_value_from_glob(paths->gl_pathv, cmd,
		ref);
		free (ref);
		globfree(paths);
		my_free_tab(ref_tab);
		int_value->check_passed_at_least_one_tour += 1;
	} else {
		replace_ref(cmd, int_value, ref_tab);
		my_free_tab(ref_tab);
	}
}

void body_glob(glob_t *paths, char **cmd, error_var_t *int_value)
{
	char *parse_star = NULL;
	int count_globcard = count_glob(*cmd);
	int retval = 0;

	while (count_globcard != 0) {
		parse_star = parse_glob(*cmd, 0);
		retval = glob(parse_star, GLOB_NOCHECK && GLOB_NOSORT
		&& GLOB_NOMATCH, NULL, paths);
		loop_glob(cmd, retval, paths, int_value);
		count_globcard--;
		free (parse_star);
	}
	parse_glob(*cmd, 1);
}

error_var_t *init_struct_var(void)
{
	error_var_t *int_value = malloc(sizeof(*int_value));

	if (!int_value)
		return (NULL);
	int_value->check_error = 0;
	int_value->check_passed_at_least_one_tour = 0;
	int_value->check_error_nomatch = 0;
	return (int_value);
}

int process_glob(char **cmd)
{
	glob_t paths;
	error_var_t *int_value = init_struct_var();

	if (!cmd)
		return (0);
	paths.gl_pathc = 0;
	paths.gl_pathv = NULL;
	paths.gl_offs = 0;
	body_glob(&paths, cmd, int_value);
	if (int_value->check_error != 0) {
		int_value->check_error = 0;
		return (1);
	}
	*cmd = my_clean_str(*cmd);
	free (int_value);
	return (0);
}