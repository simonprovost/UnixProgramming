/*
** EPITECH PROJECT, 2017
** my_minishell
** File description:
** .h
*/

#ifndef MY_MINISHELL_H
#define MY_MINISHELL_H

#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#include <memory.h>
#include "my.h"
#include "get_next_line.h"

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

//SIGNAL MACRO
#define SEG "Segmentation fault"
#define FLT_PT "Floating exception"

//OTHER MACRO'S
#define GENERAL_PATH ("PATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin")
#define SETENV_ERR ("setenv: Variable name must begin with a letter.\n")
#define SETENV_ERR_ALPHA ("setenv: Variable name must contain alphanumeric characters.\n")
#define C1 (cwd[i] == 'h')
#define C2 (cwd[i + 1] == 'o')
#define C3 (cwd[i + 2] == 'm' )
#define C4 (cwd[i + 3] == 'e')
#define TAB tab_line[0][0]
#define TAB1 tab_line[0][1]
#define TAB2 tab_line[0][2]
#define BUILTIN_L_R (tree->tright && tree->tleft && is_builtin(tree->tright->args) == 0 && is_builtin(tree->tleft->args) == 0)
#define B_ENV ((tree->tleft && my_strcmp(tree->tleft->args, "env") == 0) || (tree->tleft && my_strcmp(tree->tleft->args, "setenv") == 0))
#define N_B_ENV (tree->tleft && my_strcmp(tree->args, "env") != 0)

/*
** Operators
*/
#define SRR '>'
#define SRL '<'
#define DRR ']'
#define DRL '['
#define PIPE '|'

#define SEMICOLON ';'
#define MISSING_NAME ("Missing name for redirect.\n")
#define INVALID_CMD ("Invalid null command.\n")
#define EMPTY_OP (((tree->args != NULL)) && (count_op(tree->args) == 0))
#define FLAG_RIGHT_REDI (O_RDWR | O_CREAT | (is_otrunc == 0 ? O_TRUNC : O_APPEND))
#define FILE_TOO_LONG (": File name too long.\n")
#define IS_A_DIRR (": is a directory.\n")
#define P_DENIED (": Permission denied.\n")

//########################################STRUCTURE########################################//
typedef struct my_func_s {
	char *balise;
	void (*my_func)();
} my_func_t;

typedef struct redirect_s {
	char balise;
	int (*my_func)();
} redirect_t;

typedef struct bucket_s {
	char *key;
	void *value;
	int mallocated;
	struct bucket_s *next;
} my_bucket_t;

typedef struct hashmap_s {
	unsigned int size;
	my_bucket_t **data;
} hashmap_t;

typedef struct binary_tree_s {
	int exec;
	char operator;
	char *args;
	struct binary_tree_s *tleft;
	struct binary_tree_s *tright;
	struct binary_tree_s *parent;
} binary_tree_t;

typedef struct info_shell_s {
	char **env;
	char **args_redirect;
	char *op_redirect;
	char *line;
	char *my_old_pwd;
	char *file_name;
	int check_if_something_happened;
	int return_value;
	int last_elem_parser;
	int fd_fileno[2];
	int error;
	int pos_pointer;
	binary_tree_t *tree_args;
} info_shell_t;


//########################################STRUCTURE########################################//

//########################################MY LIB########################################//
char **str_to_word_array(char *);
char **split_setenv(char *);
int my_strncmp(char *, char *, int );
int my_strcmp(char *, char *);
char *my_strcat(char *, char *);
void my_epur_str(char *);
char **my_array_dup(char **);
char *my_strdup(char *);
void my_epur_str(char *);
char *my_strcpy(char *, char *);

//########################################LIB _ SHELL########################################//
int count_env(char **);
void show_getcwd(void);

//########################################LIB _ HASHMAP########################################//
//FILL_ENV_HASH
char **fill_env_with_hashmap(hashmap_t *, char **);
hashmap_t *fill_hashmap_with_env(hashmap_t *, char **);

//FREE/DESTROY HASH
void free_tab(char **);
void bucket_destroy(my_bucket_t *);
void destroy_ll_bucket(hashmap_t *);
void hm_destroy(hashmap_t *);

//ADD VALUE TO HASH
char **update_my_env_add_case(char *, hashmap_t *, char **);
char **add_value_to_env(hashmap_t *, char *, char *, char **);
int special_case_delete(hashmap_t *, char *);

//DELETE VALUE TO HASH
char **delete_case_hashmap(hashmap_t *, char *, char **);
char **update_my_env_delete_case(char *, hashmap_t *, char **);
char **replace_case_hashmap(hashmap_t *, char *, char *,
char **);

//KEY/VALUE COPY TO RETURN A CHAR* OF THIS STRING GET.
char *my_value_copy(char *, char);
char *my_key_copy(char *, char);

//LIB HASHMAP
void hm_add(hashmap_t *, char *, void *);
void hm_linked_list_add(my_bucket_t **, my_bucket_t *);
my_bucket_t *hm_create_bucket(char *, void *);
hashmap_t *hm_create(unsigned int);
char *get_anything_value(hashmap_t *, char *);
void *hm_get(hashmap_t *, char *);
my_bucket_t *hm_get_bucket(hashmap_t *, char *);
unsigned int hm_hash(hashmap_t *, char *);

//PRINT
void print_tab(char **);
void print_hashmap(hashmap_t *, char **);

//BUILT IN AND BINARY EXEC
void check_what_is_the_error_msg(int, info_shell_t *);
void check_return(char *, int, info_shell_t *);
void verif_signal(int, info_shell_t *);
int proccess_if_file_exit(char *, char **, info_shell_t *);
int process_builtin(hashmap_t *, char *, info_shell_t *);
int process_no_builtin(hashmap_t *, char *, info_shell_t *);
int process_builtin_no_builtin(hashmap_t *, info_shell_t *);
char **fill_tab_with_userinput(char *, char *);
void test_if_is_binary_and_can_run(char *, info_shell_t *);
void test_with_dot_slash(info_shell_t *);
int test_access_with_tab(char *, info_shell_t *, hashmap_t *, int);
int process_redirection(info_shell_t *, hashmap_t *, int);
int count_op(char *);

//NO BUILT IN FUNC
void manage_cd(hashmap_t *, char *, info_shell_t *);
void manage_env(hashmap_t *, char *, info_shell_t *);
void manage_setenv(hashmap_t *, char *, info_shell_t *);
void manage_unsetenv(hashmap_t *, char *, info_shell_t *);
void manage_exit(hashmap_t *, char *, info_shell_t *);

//PRE POCESSS
int pre_process_programm(char **, hashmap_t **, info_shell_t *);

//FREE PROJECT
void free_all(char **, hashmap_t *);

// ######################## LIB _ BINARY TREE ########################
binary_tree_t *create_new_tree(char, char*);
void destroy_binary_tree(binary_tree_t *);
binary_tree_t *join_tree(binary_tree_t *, binary_tree_t *, char, char *);
void print_tree_prefix(binary_tree_t *);
void print_tree_postfix(binary_tree_t *);
int count_tree_nodes(binary_tree_t *);
void process_new_node(char , info_shell_t *, binary_tree_t *, int);
binary_tree_t *new_branch(char, char *, binary_tree_t *);
binary_tree_t *load_binary_args(binary_tree_t *);
void check_if_name_too_long(char *, struct stat, info_shell_t *);
int is_builtin(char *);

// ######## ERRROR HANLDING ######### //
int is_op_or_arg(char *);
int is_same_op(char *, char *);
int size_tab(char **);
int is_arg(char *);
int error_handling_redirect(info_shell_t *);
int check_first_elem(char **, info_shell_t *);
int verif_op(char *, info_shell_t *);
int ambiguous_redirect(int, char *);
int check_another_elem(char **, info_shell_t *);
int check_another_next_elem(char **, info_shell_t *, int);

// ######### PARSER ##########//
binary_tree_t *binary_parser_semicolon(char *, binary_tree_t *);
binary_tree_t *binary_parser_pipe_redirect(char *, binary_tree_t *, int );
binary_tree_t *load_binary_args(binary_tree_t *);
int count_op(char *);
char *load_op(char *);
int parser_line(info_shell_t *);

// ######### REDIRECTION ############ //
char *load_op(char *);
int test_access_with_tab_bt(char *, info_shell_t *, hashmap_t *, int);
int manage_semicolon(binary_tree_t *, info_shell_t *, hashmap_t *, int);
int manage_pipe(binary_tree_t *, info_shell_t *, hashmap_t *, int);
int proc_pipe(binary_tree_t *, info_shell_t *, hashmap_t *, int );
int proccess_exec_node(binary_tree_t *, info_shell_t *, hashmap_t *, int);
int manage_right(binary_tree_t *, info_shell_t *, hashmap_t *, int);
void print_correct_file_error(char *s);
int manage_left(binary_tree_t *, info_shell_t *, hashmap_t *, int );
int manage_double_left_redirection(binary_tree_t *, info_shell_t *, hashmap_t *, int);
int exec_last_node(binary_tree_t *, hashmap_t *, info_shell_t *, int);
void last_verif_of_last_node(info_shell_t *, int , int);
void exec_childlast_node(binary_tree_t *, hashmap_t *, info_shell_t *, int);
int err_handling_last(binary_tree_t *, int, info_shell_t *, int);
char **fill_tab_with_userinput(char *, char *);
void check_without_cd(info_shell_t *);
int before_loop(char **env, hashmap_t **hashmap,
info_shell_t *info_shell);


//bonus func
void bonus_cd(info_shell_t *info_shell);
void check_signal(void);
void sig_handler(int signo);
#endif
