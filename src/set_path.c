/*
** EPITECH PROJECT, 2018
** set_path.c
** File description:
** set_path.c
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

pid_t create_process(void)
{
	pid_t pid = fork();

	return (pid);
}

void destroy_path_variable(char **str, int lines)
{
	int i = 0;

	while (i != lines) {
		free(str[i]);
		i = i + 1;
	}
	free(str);
}

char **find_and_set_PATH_variable(char **env, int *lines)
{
	char **path;
	char *str;
	int i = 0;
	int j = 5;
	int k = 0;

	while (env[i][0] != 'P' || env[i][1] != 'A' ||
	env[i][2] != 'T' || env[i][3] != 'H' || env[i][4] != '=')
		i = i + 1;
	str = malloc(sizeof(char) * my_strlen(env[i]) - 4);
	while (env[i][j] != '\0') {
		str[k] = env[i][j];
		j = j + 1;
		k = k + 1;
	}
	str[k] = '\0';
	*lines = nombre_ligne(str, ':');
	path = str_to_array(str, ':');
	free(str);
	return (path);
}
