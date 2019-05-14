/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "42sh.h"

void add_new_value_from_glob(char **tab, char **cmd, char *ref)
{
	char **tab_tmp = my_str_to_word_array(*cmd, ' ');
	char *ret_convert = NULL;
	int pos_ref = check_whereis_ref(tab_tmp, ref);

	ret_convert = convert_tab_to_string(tab);
	tab_tmp[pos_ref] = strdup(ret_convert);
	*cmd = convert_tab_to_string(tab_tmp);
	free (ret_convert);
	my_free_tab(tab_tmp);
}

void clear_string_pointer(char **string, char user_choice)
{
	char *tmp = strdup(*string);

	for (int i = 0 ; tmp[i] ; i++)
		tmp[i] = user_choice;
	*string = strdup(tmp);
	free (tmp);
}

int check_no_match(error_var_t *int_value, char **ref_tab, char **cmd)
{
	if (int_value->check_passed_at_least_one_tour != 1
	&& int_value->check_error_nomatch != 1
	&& check_brackets(*cmd) != 1) {
		printf("%s: No match.\n", ref_tab[0]);
		int_value->check_error_nomatch = 1;
		int_value->check_error = 1;
		return (1);
	}
	return (0);
}

void replace_ref(char **cmd, error_var_t *int_value,
char **ref_tab)
{
	char *ref = NULL;
	char **tmp_tab = NULL;

	if (check_no_match(int_value, ref_tab, cmd) != 0)
		return;
	if ((ref = parse_glob(*cmd, 2)) == NULL ||
	(tmp_tab = my_str_to_word_array(*cmd, ' ')) == NULL)
		return;
	for (int i = 0 ; tmp_tab[i] ; i++) {
		if (strcmp(ref, tmp_tab[i]) == 0) {
			clear_string_pointer(&(tmp_tab[i]), ' ');
			*cmd = convert_tab_to_string(tmp_tab);
			my_free_tab(tmp_tab);
			free (ref);
			return;
		}
	}
	my_free_tab(tmp_tab);
	free (ref);
}