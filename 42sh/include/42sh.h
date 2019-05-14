/*
** EPITECH PROJECT, 2018
** my exec 2
** File description:
** 42sh
*/

#ifndef	__42sh__
#define	__42sh__

#include "my.h"
#include <glob.h>
#include <ctype.h>
#include <stdbool.h>

#define PATH_42SH ".42shrc"
#define UNUSED(x) (void)(x)
#define FILE_TOO_LONG ("%s: File name too long.\n")
#define N_MAX 255

typedef struct shell_s shell_t;
typedef struct env_s env_t;
typedef struct btree_s btree_t;
typedef struct ll_alias_s ll_alias_t;
typedef struct ll_lvar_s ll_lvar_t;
typedef struct error_var_s error_var_t;

typedef struct error_var_s
{
	int check_error;
	int check_passed_at_least_one_tour;
	int check_error_nomatch;
} error_var_t;

typedef struct ll_alias_s
{
	char *name;
	char *alias;
	int par;
	ll_alias_t *next;
} ll_alias_t;

typedef struct ll_lvar_s
{
	char *name;
	char *value;
	ll_lvar_t *next;
} ll_lvar_t;

typedef struct shell_s {
	env_t *env;
	ll_alias_t *aliases;
	ll_lvar_t *local_var;
} shell_t;

typedef struct env_s {
	char *name;
	char *value;
	env_t *next;
} env_t;

typedef struct btree_s {
	char *op;
	char *cmd;
	int fd[2];
	btree_t *left;
	btree_t *right;
} btree_t;

typedef struct operator_s {
	char *op;
	void (*fptr)(btree_t *, shell_t, int *);
} operator_t;

typedef struct builtin_s {
	char *name;
	void (*fptr)(char **, shell_t, int *);
} builtin_t;

env_t *global_env;

void sig_handler(int sig_num);
int count_args(char **cmd);
void display_args(char **cmd);
char *get_line(void);
void my_loop(shell_t shell, int);
char *get_dir(env_t *env);
int my_exec(char **cmd, env_t *env, int *ret_value);
void my_exec_pipe(btree_t *, env_t *env, int *ret_value, int *fd);
void print_prompt(env_t *env);
char *concat_exec(char **cmd, env_t *env);
env_t *create_list(char **cmd);
void env_func(char **cmd, shell_t shell, int *ret_value);
char **list_to_2d_arr(env_t *env);
char *get_env(env_t *env, char *);
int find_command_size(char **cmd);
env_t *fill_my_env(env_t *env);
int verif_env(char **cmd);
void sig_handler(int);
int check_segfault(int);
void free_list(env_t *env);
void change_pwd(env_t *env);
void free_btree_node(btree_t *);
btree_t *create_btree_node(char *, char *);
void parse_cmd(shell_t shell, char *, int *ret_value);
int parse_cmd_for_pipes_and_redirections(btree_t *tree);
int parse_cmd_for_semicolon(btree_t *tree);
int parse_cmd_for_and(btree_t *node);
int parse_cmd_for_or(btree_t *node);
void exec_tree(btree_t *tree, shell_t shell, int *ret_value);
int set_pipefd(btree_t *tree);
void exec_semicolon(btree_t *tree, shell_t shell, int *ret_value);
void exec_double_and(btree_t *tree, shell_t shell, int *ret_value);
void exec_double_or(btree_t *tree, shell_t shell, int *ret_value);
void exec_pipe(btree_t *tree, shell_t shell, int *ret_value);
void exec_right_redirect(btree_t *tree, shell_t shell, int *ret_value);
void exec_double_right_redirect(btree_t *tree, shell_t shell, int *ret_value);
void exec_left_redirect(btree_t *tree, shell_t shell, int *ret_value);
void exec_double_left_redirect(btree_t *tree, shell_t shell, int *ret_value);
int redirect_error_handling(int, char **cmd, env_t *env, int *ret_value);
int btree_error_handling(btree_t *tree, int);
int parse_env_variables(char **str, shell_t shell);
void parse_inhibitors(char **str);
int check_quotes(char *cmd, int i);
int check_bad_quotes(char *cmd);
int is_a_built_in(char *str);
int test_concat_exec(char *test_access, char **path, char **str);
char **parse_quotes(char **cmd);
void update_iterator(char *str, int *i, bool *d_quote);
void update_iterator_for_quotes(char *str, int *i);

// GLOBBING
int process_globbing(char **cmd);
char *convert_tab_to_string(char **tab);
int check_glob(char *cmd);
char *parse_glob(char *cmd, int clean);
int count_glob(char *cmd);
int process_glob(char **cmd);
int check_brackets(char *cmd);
void replace_ref(char **cmd, error_var_t *int_value, char **ref_tab);
int check_no_match(error_var_t *int_value, char **ref_tab, char **cmd);
void clear_string_pointer(char **string, char user_choice);
void add_new_value_from_glob(char **tab, char **cmd, char *ref);
int check_whereis_ref(char **tab , char *ref);

//ALIAS
void synchro_with_file(ll_alias_t *n);
int check_name_exist(ll_alias_t *lla, char *name, char *alias);
void add_alias(char *name, char *alias, ll_alias_t *lla, int par);
void print_alias(ll_alias_t *n);
ll_alias_t *init_lla(void);
void sort_lla(ll_alias_t *lla);
void my_free_lla(ll_alias_t *lla);
char *get_str_alias(char **str);
int alias_loop(ll_alias_t *tmp, ll_alias_t *lla);
int alias_is_another(char *alias, ll_alias_t *lla);
ll_alias_t *step_up_alias(char *alias, ll_alias_t *lla, int *ret);
char **my_strtab_cat(char **cmd, char **str);
char *get_file(char *path);
void write_alias(ll_alias_t *lla);
char **get_alias(char *line);
int replace_alias(btree_t *tree, ll_alias_t *lla);

//LOCAL_VAR
ll_lvar_t *init_lvar(void);
void create_lvar(char *name, char *value, ll_lvar_t *lvar);
int replace_lvar(char *name, char *value, ll_lvar_t *lvar);
void create_lvar(char *name, char *value, ll_lvar_t *lvar);
void add_valid_lvar(ll_lvar_t *lvar, char **str, int i, int *ret_value);
int there_is_a_equal(char *str);
int begin_with_letter(char *str);
int is_int(char c);
int check_too_deep(char *str);
int is_sorted_lvar(ll_lvar_t *lvar);
void swap_elem_lvar(ll_lvar_t *lvar1, ll_lvar_t *lvar2);
void sort_lvar_core(ll_lvar_t *tmp);
void sort_lvar(ll_lvar_t *lvar);
void print_lvar(ll_lvar_t *lvar);
void create_lvar(char *name, char *value, ll_lvar_t *lvar);
char *get_lvar_one(char *str);
char *get_lvar_two(char *str);
int valid_lvar(char *str);
char *get_lvar(char *name, ll_lvar_t *list);

// BUILTIN
int check_built_ins(char **cmd, shell_t shell, int *ret_value, int *fd);
void repeat_func(char **str, shell_t shell, int *ret_value);
void if_func(char **str, shell_t shell, int *ret_value);
void foreach_func(char **str, shell_t shell, int *ret_value);
void unsetenv_func(char **cmd, shell_t shell, int *ret_value);
void cd_func(char **cmd, shell_t shell, int *ret_value);
void where_func(char **cmd, shell_t shell, int *ret_value);
void which_func(char **cmd, shell_t shell, int *ret_value);
void exit_func(char **cmd, shell_t shell, int *ret_value);
void setenv_func(char **cmd, shell_t shell, int *ret_value);
void echo_func(char **cmd, shell_t shell, int *ret_value);
void set_func(char **str, shell_t shell, int *ret_value);
void unset_func(char **str, shell_t shell, int *ret_value);
void alias_func(char **str, shell_t shell, int *ret_value);
void unalias_func(char **str, shell_t shell, int *ret_value);
int count_loop_foreach(char **str);

//SCRIPTING

void replace_argument(char **parsed, char **arguments, int i);
void seek_arguments(char **parsed, char **arguments);
char *replace_arguments(char *buffer, char **arguments);
int seek_script(shell_t shell, char **binary, int *ret_value);

// UTILS
int is_alpha_string(char *str);
void print_tab(char **tab);
int my_str_is_alphanum(char *str);

// IF
int check_only_number(char **s, int *ret_if);
int check_error_handling_if(char **str);
int is_if_error(char **s);
int check_then_if(char **s, shell_t shell);
int process_then(char *str, shell_t shell);
int check_then(char **s);
int process_if(char **str, shell_t shell);
int is_parenthese(char *str);
int parse_if(char **str);
char **set_null_empty_case_tab(char **str);
char **clean_tab(char **str);
int my_memmove(char **s1, char **s2);
int empty_string(char *str);
void clean_parenthesis(char **str);
int check_expression(char **str);
char **set_null_empty_case_tab(char **str);
char **clean_tab(char **str);
int empty_string(char *str);
void clean_parenthesis(char **str);
char **memmove_tab(char **str);
int pos_empty_case(char **str);
int need_to_memmove(char **str);
int missing_parenthesis(char *temp);
int expression_syntax_if(char *tmp);
int check_badly(char *str);
int empty_if(char *temp);
int too_few_args(char *tmp, int paren);
char *delete_all_parenthese(char **str, int *parenthesis);


//UTILS FOREACH
int count_parenthesis(char **str);

#endif /* __42sh__ */
