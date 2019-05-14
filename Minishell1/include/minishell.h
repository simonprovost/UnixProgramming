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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#include "my.h"
#include "get_next_line.h"
#define BUFF_SIZE 1024
#define CFT check_if_two
#define SEG "Segmentation fault"
#define FLT_PT "Floating exception"
#define UNUSED(x) (void)(x)
#define GENERAL_PATH ("PATH=/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin")
#define SETENV_ERR ("setenv: Variable name must begin with a letter.\n")
#define SETENV_ERR_ALPHA ("setenv: Variable name must contain alphanumeric characters.\n")
#define SIZE_ENV_J (my_strlen(env[j]))
#define STRLEN_ARGS (my_strlen(my_args))
#define INFO_I (my_info[1][0])
#define I_ERR (my_info[1][i])
#define MF (my_info)
#define CHECK_S info->check_setenv
#define I_SPA info->size_path_array
#define C1 (cwd[i] == 'h')
#define C2 (cwd[i + 1] == 'o')
#define C3 (cwd[i + 2] == 'm' )
#define C4 (cwd[i + 3] == 'e')

extern char **global_env;

typedef struct my_func_s {
	char *balise;
	void (*my_func)();
} my_func_t;

typedef struct info_s {
	char **info;
	int argc;
	int size;
	int my_loc;
	char **path;
	char **env;
	int size_path_array;
	int pos_path;
	int count_args;
	int run_env;
	char *my_old_pwd;
	char *my_current_pwd;
	char *s;
	int check_if_some_things_happened;
	int check_env_not_found;
	int pos_set_env;
	int check_setenv;
	char *s_save;
	int pos_old;
	int pos_current;
} info_t;

char **str_to_word_array(char *);
void print_env(info_t *);
void check_env(info_t *);
void fill_info(info_t *, char *);
void show_double_tab(info_t *);
char *my_strcat_shell(char *, char *);
int found_env(char **);
void change_dir(char *, info_t *);
void exit_func(char *, info_t *);
void set_env_func(char *, char **, info_t *);
int my_strncmp(char const *, char const *, int );
int my_strcmp(char const *, char const *);
void unset_env_func(char *, char **, info_t *);
void env_print_func(char *, info_t *);
void check_args_exit(char *, int , info_t *);
void exit_func_one_args(char *, info_t *);
char *fill_final_return_exit(char *, char *, int );
void badly_formed_func(char *, int *, int *);
char **fill_each_case(char **, char **);
char **malloc_each_case(char **, char **, char **, info_t *);
int check_if_fail_args(char *, info_t *, int);
int size_env(char **);
void find_in_path(char *, info_t *);
int count_args_unsetenv(char *);
char **fill_each_case_unset(char **, char **, int);
char **malloc_each_case_unset(char **, char **, int);
void handling_error(char **, char *, info_t *, int);
int check_info(char **);
char *my_strcat(char *, char *);
void my_epur_str(char *);
void check_few_args(int , info_t *);
void check_cd_moin(info_t *, struct stat, char *, int);
void check_if_args(int , char *, struct stat, info_t *);
void check_if_cd_only(int , char *, struct stat, info_t *);
void print_file_or_folder_if_fail_cd(info_t *);
void check_if_name_too_long(info_t *, struct stat);
int count_args_cd(char *);
char *fill_return_to_home(char *);
char *find_home_dirr(info_t *);
char *fill_return_to_path(char *);
char *find_path_user(char *);
int found_in_str(char *, char *);
int func_to_read_size(info_t *);
int func_to_found_old(info_t *);
int func_to_found_pwd(info_t *);
char **malloc_each_case_update(char **, char **, info_t *);
char **fill_each_case_update(char **, char **, info_t *);
char **update_env(info_t *);
void old_pwd_with_only_path(info_t *, int);
int check_s(char *);
void change_dir(char *, info_t *);
void cd_only(struct stat, info_t *, char *, char *);
void cd_with_args(struct stat, info_t *, char *);
void cd_moin(struct stat, info_t *, char *);
void my_child(int status);
void show_programm_user(info_t *, char *, char **);
int found_env(char **);
int found_host(char **);
void next_getbackn(char *, int *i);
int getbackn(char *);
int next_find_home(char *);
int find_home(char *);
void show_getcwd(void);
void show_host(char **);
void found_size_path_array(info_t *);
char *fill_path(char *, char *);
void test_if_you_have_access(info_t *, char *);
void show_hos_and_dirr(char **);
void fill_begin_info(info_t *, int, char **);
int check_strncmp_with_tab_func(char *, char *);
void next_check_if_built_in(char *, info_t *, int j);
int check_if_built_in(char *, info_t *);
void analyse_user_input(info_t *, char *, char *);
int check_if_empty(char *);
void print_correct_file_error(char *);
int check_badly_next(char *, int, int, int *);
int check_badly_number(char *, int *);
char **my_strdup(char **);
int count_env(char **);
void free_all(char *, info_t *);
void next_access_func(char *, info_t *, int *);
void show_host(char **);
void show_getcwd(void);
void show_programm_user(info_t *, char *, char *[]);
void check_return(int, info_t *, int);
void check_what_is_the_error_msg(int);
int found_next_next(int *, char *, char *);
char *find_path_user(char *);
char *fill_return_to_path(char *);
char *find_home_dirr(info_t *);
char *fill_return_to_home(char *);
void badly_formed_func(char *, int *, int *);
char *fill_final_return_exit(char *, char *, int);
void free_exit_func_one_args(char *, char *, info_t *);
void exit_func_one_args(char *, info_t *);
void check_args_exit(char *, int, info_t *);
int size_env_setenv(char **);
int check_if_fail_args_setenv(char *, info_t *);
char **malloc_setenv(char **, char **, char **, info_t *);
char **fill_each_case_setenv(char **, char **);
int detect_who_is_it_setenv(info_t *, char **);
char **fill_each_case_unset_unset(char **, char **, int);
int count_args_unsetenv_unset(char *);
void free_env_unset(info_t *);
void find_in_path_unset(char *, info_t *);
void begin_programm(info_t *, int, char **);
void loop_main(char *, info_t *, char *);
void check_signal(void);
void sig_handler(int );
void check_tty(char **);
char **fill_each_case_setenv(char **, char **);
int fail_args_three(char *, info_t *, int);
char *my_strdup_simple(char *);
char *new_path_test(info_t *, char *, int i);
#endif
