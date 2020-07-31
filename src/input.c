/*
** EPITECH PROJECT, 2018
** input.c
** File description:
** input.c
*/

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

char *get_input(char **str)
{
	*str = get_next_line(0);
	if (*str == NULL)
		return (NULL);
	*str = pur_str(*str);
	return (*str);
}

int count_char(char *str, char c)
{
	int i = 0;
	int spaces = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			spaces = spaces + 1;
		i = i + 1;
	}
	return (spaces);
}

void *exec_input(char **path, char *input, char **new_env, int check, int *value)
{
	if (check == 0) {
		if (execute_order(path, input, new_env, value) == 84)
			return (NULL);
	}
	else {
		new_env = execute_builtin(input, new_env, value);
		if (new_env == NULL)
			return (NULL);
	}
	return (new_env);
}

void *wait_and_get_input(char *input, char **path, int lines, int *value)
{
	if (isatty(0) == 1)
		write(0, "$>", 3);
	if (get_input(&input) == NULL) {
		if (isatty(0) == 1)
			my_putchar('\n');
		free(input);
		destroy_path_variable(path, lines);
		if (*value == 1)
			exit(1);
		else if (*value == 139)
			exit(139);
		else
			exit(EXIT_SUCCESS);
	}
	*value = 0;
	return (input);
}

int execute_order(char **path, char *input, char **new_env, int *value)
{
	int i = 0;
	pid_t pid;
	int status = 0;
	char *order = NULL;
	char **input_tab = str_to_array(pur_str(input), ' ');
	char **new_arg;

	if (count_char(input_tab[0], '/') != 0) {
		new_arg = set_new_arg(input, input_tab,
		nombre_ligne(input, ' '));
		if (access(input_tab[0], X_OK) != 0) {
			write(1, input_tab[0], my_strlen(input_tab[0]));
			write(1, ": Command not found.\n", 21);
			*value = 1;
		}
		else {
			if ((pid = create_process()) == 0)
				execve(input_tab[0], new_arg, new_env);
			wait(&status);
			if (WCOREDUMP(status)) {
				my_printf("Segmentation fault\n");
				*value = 139;
			}
		}
		return (1);
	}
	do {
		order = my_strcat(path[i], "/");
		order = my_strcat(order, pur_str(input_tab[0]));
		i = i + 1;
	} while (path[i] != NULL && access(order, F_OK && R_OK) != 0);
	if (path[i] == NULL) {
		write(1, input, my_strlen(input));
		write(1, ": Command not found.\n", 21);
		*value = 1;
		return (1);
	}
	new_arg = set_new_arg(order, input_tab, nombre_ligne(input, ' '));
	if ((pid = create_process()) == 0)
		execve(order, new_arg, new_env);
	wait(NULL);
	return (0);
}
