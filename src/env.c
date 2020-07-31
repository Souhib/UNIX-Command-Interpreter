/*
** EPITECH PROJECT, 2018
** env.c
** File description:
** env.c
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

int check_name(char **new_env, char **input)
{
	int cmp[3] = {0, 0, 0};

	while (new_env[cmp[i]] != NULL) {
		while (input[1][cmp[k]] == new_env[cmp[i]][cmp[j]] &&
		input[1][cmp[k]] != '\0') {
			cmp[j] = cmp[j] + 1;
			cmp[k] = cmp[k] + 1;
		}
		if (input[1][cmp[k]] == '\0')
			return (0);
		cmp[i] = cmp[i] + 1;
		cmp[j] = 0;
		cmp[k] = 0;
	}
	return (1);
}

char **set_new_env(char **new_env, char **input_tab)
{
	char **str;
	int i = 0;
	int j = 0;

	while (new_env[i] != NULL)
		i = i + 1;
	if ((str = malloc(sizeof(char *) * i + 2)) == NULL)
		return (NULL);
	while (new_env[j] != NULL) {
		if ((str[j] = malloc(sizeof(char) *
		my_strlen(new_env[j]))) == NULL)
			return (NULL);
		str[j] = my_strcpy(str[j], new_env[j]);
		j = j + 1;
	}
	if ((str[j] = malloc(sizeof(char))) == NULL)
		return (NULL);
	str[j][0] = '\0';
	if ((str[j] = my_strcat(str[j], input_tab[1])) == NULL)
		return (NULL);
	if ((str[j] = my_strcat(str[j], "=")) == NULL)
		return (NULL);
	if (input_tab[2] != NULL) {
		if ((str[j] = my_strcat(str[j], input_tab[2])) == NULL)
			return (NULL);
	}
	str[j + 1] = NULL;
	return (str);
}

char **unset_env(char *input_name, char **new_env)
{
	char **str;
	int i = 0;
	int j = 0;
	int k = 0;

	if (input_name == NULL) {
		my_printf("unsetenv: Too few arguments.\n");
		return (new_env);
	}
	while (new_env[i] != NULL)
		i = i + 1;
	if ((str = malloc(sizeof(char *) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (new_env[j] != NULL) {
		while (input_name[i] == new_env[j][i] && new_env[j][i] != '\0')
			i = i + 1;
		if (input_name[i] == '\0' && new_env[j + 1] != NULL)
			j = j + 1;
		if (new_env[j + 1] == NULL) {
			str[k] = NULL;
			return (str);
		}
		if ((str[k] = malloc(sizeof(char) *
		my_strlen(new_env[j]))) == NULL)
			return (NULL);
		str[k] = my_strcpy(str[k], new_env[j]);
		k = k + 1;
		j = j + 1;
		i = 0;
	}
	str[k] = NULL;
	return (str);
}

char **set_env(char **new_env, char **input)
{
	new_env = set_new_env(new_env, input);
	if (new_env == NULL)
		return (NULL);
	return (new_env);
}
