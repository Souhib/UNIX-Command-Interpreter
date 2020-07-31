/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
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

char **set_new_arg(char *order, char **input_tab, int lines)
{
	int i = 1;
	char **str = malloc(sizeof(char *) * lines + 1);

	str[0] = malloc(sizeof(char) * my_strlen(order));
	str[0] = order;
	while (i != lines) {
		str[i] = malloc(sizeof(char) * my_strlen(input_tab[i]));
		str[i] = input_tab[i];
		i = i + 1;
	}
	return (str);
}

void *minishell2(char **env)
{
	int lines = 0;
	int check = 0;
	int value = 0;
	char *builtin[3] = {"exit", "unsetenv", "cd"};
	char **path = find_and_set_PATH_variable(env, &lines);
	char *input = malloc(sizeof(char));
	char **new_env = env;

	if (path == NULL)
		return (NULL);
	while (1) {
		input = wait_and_get_input(input, path, lines, &value);
		check_builtin(input, builtin, &check);
		new_env = exec_input(path, input, new_env, check, &value);
		if (new_env == NULL)
			return (NULL);
		check = 0;
	}
}

int main(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (84);
	else if (env[0] == NULL)
		return (84);
	if (argv[0] == NULL)
		return (84);
	if (minishell2(env) == NULL)
		return (84);
	return (0);
}
