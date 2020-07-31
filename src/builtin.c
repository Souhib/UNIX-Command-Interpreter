/*
** EPITECH PROJECT, 2018
** builtin.c
** File description:
** builtin.c
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "gnl.h"
#include "mysh.h"

void env(char **env)
{
	int i = 0;
	while (env[i] != NULL) {
		my_putstr(env[i]);
		my_putchar('\n');
		i = i + 1;
	}
}

char **check_which_builtin(char *input, char **new_env)
{
	char **tab_input = str_to_array(input, ' ');

	if (tab_input == NULL)
		return (NULL);
	if (my_strcmp(tab_input[0], "setenv") == 0) {
		if (count_char(input, ' ') == 0)
			env(new_env);
		else if ((new_env = set_env(new_env, tab_input)) == NULL)
			return (NULL);
	}
	if (my_strcmp(tab_input[0], "unsetenv") == 0)
		new_env = unset_env(tab_input[1], new_env);
	if (my_strcmp(tab_input[0], "cd") == 0 ||
	my_strcmp(pur_str(input), "cd") == 0)
		new_env = change_directory(new_env, tab_input[1], input);
	if (new_env == NULL)
		return (NULL);
	return (new_env);
}

char **execute_builtin(char *input, char **new_env, int *value)
{
	pid_t pid;
	int status = 0;
	char **tab_input = str_to_array(input, ' ');
	int check = 0;

	if (tab_input == NULL)
		return (NULL);
	if ((new_env = check_which_builtin(input, new_env)) == NULL)
		return (NULL);
	if (tab_input[0][0] == '.' && tab_input[0][1] == '/') {
//		if ((pid = create_process()) == 0) {
//			if (execve(tab_input[0], tab_input, new_env) == -1) {
		if (access(tab_input[0], X_OK && R_OK && F_OK) != 0) {
			my_printf("%s: Permission denied.\n", input);
			check = 1;
			*value = 1;
			return (new_env);
		}
		else {
			if ((pid = create_process()) == 0)
				execve(tab_input[0], tab_input, new_env);
		}
//		}
		wait(&status);
		if (check == 1)
			*value = 1;
		if (WCOREDUMP(status)) {
			my_printf("Segmentation fault\n");
			*value = 139;
		}
	}
	return (new_env);
}

void *check_builtin(char *input, char **builtin, int *check)
{
	int i = 0;
	char **input_tab = str_to_array(input, ' ');

	while (i != 3) {
		if (my_strcmp(input, builtin[i]) == 0)
			*check = 1;
		i = i + 1;
	}
	if (input[0] == '.' && input[1] == '/')
		*check = 1;
	if (my_strcmp(input, "setenv") == 0)
		*check = 1;
	if (count_char(input, ' ') != 0) {
		if (my_strcmp(input_tab[0], "unsetenv") == 0 ||
		my_strcmp(input_tab[0], "setenv") == 0 ||
		my_strcmp(input_tab[0], "cd") == 0)
			*check = 1;
	}
	destroy_path_variable(input_tab, nombre_ligne(input, ' '));
	return (0);
}
