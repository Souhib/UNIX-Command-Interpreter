/*
** EPITECH PROJECT, 2018
** mysh.h
** File description:
** mysh.h
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "gnl.h"
#include "mysh.h"

enum nb {
	i = 0, j, k,
};

char **execute_builtin(char *input, char **new_env, int *value);
pid_t create_process(void);
int count_char(char *str, char c);
char **cd_dash(char **env, char **old_pwd);
char **simple_cd(char **env, char *str, char **old_pwd, int i);
char **cd_only(char **env, char **old_pwd, int i);
char **change_directory(char **env, char *str, char *input);
int check_name(char **new_env, char **input);
char **set_new_env(char **new_env, char **input_tab);
char **unset_env(char *input_name, char **new_env);
char **set_env(char **new_env, char **input);
void *check_builtin(char *input, char **builtin, int *check);
char *get_input(char **str);
int count_char(char *str, char c);
void *exec_input(char **path, char *input, char **new_env, int check, int *value);
void *wait_and_get_input(char *input, char **path, int lines, int *value);
pid_t create_process(void);
void destroy_path_variable(char **str, int lines);
char **find_and_set_PATH_variable(char **env, int *lines);
int execute_order(char **path, char *input, char **new_env, int *value);
char **set_new_arg(char *order, char **input_tab, int lines);

#endif /* MYSH_H_ */