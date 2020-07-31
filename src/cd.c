/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** cd.c
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

char **cd_dash(char **env, char **old_pwd)
{
	if (*old_pwd == NULL) {
		my_printf(": No such file or directory.\n");
		return (env);
	}
	return (env);
}

char **simple_cd(char **env, char *str, char **old_pwd, int i)
{
	DIR *dir = opendir(str);
	char *path = malloc(sizeof(char));

	if (dir == NULL) {
		my_printf("%s: Not a directory.", str);
		return (env);
	}
	path[0] = '\0';
	*old_pwd = malloc(sizeof(char));
	*old_pwd = my_new_strcpy(*old_pwd, "OLDPWD=");
	*old_pwd = my_strcat(*old_pwd, my_cutstr(env[i], 4));
	path = my_cutstr(env[i], 4);
	path = my_strcat(path, "/");
	path = my_strcat(path, str);
	env[i] = my_strcat(env[i], "/");
	env[i] = my_strcat(env[i], str);
	if (chdir(path) == -1)
		my_printf("%s: No such file or directory.\n", str);
	return (env);
}

char **cd_only(char **env, char **old_pwd, int i)
{
	int k = 0;

	while (env[k][0] != 'H' || env[k][1] != 'O' ||
		env[k][2] != 'M' || env[k][3] != 'E' ||
		env[k][4] != '=')
		k = k + 1;
	chdir(my_cutstr(env[k], 5));
	*old_pwd = malloc(sizeof(char));
	*old_pwd = my_new_strcpy(*old_pwd, "OLDPWD=");
	*old_pwd = my_strcat(*old_pwd, my_cutstr(env[i], 4));
	env[i] = my_new_strcpy(env[i], "PWD=");
	env[i] = my_strcat(env[i], my_cutstr(env[k], 5));
	return (env);
}

char **change_directory(char **env, char *str, char *input)
{
	int i = 0;
	static char *old_pwd = NULL;

	while (env[i][0] != 'P' || env[i][1] != 'W' ||
		env[i][2] != 'D' || env[i][3] != '=')
		i = i + 1;
	if (count_char(pur_str(input), ' ') == 0)
		env = cd_only(env, &old_pwd, i);
	else if (my_strcmp(str, "-") == 0)
		env = cd_dash(env, &old_pwd);
	else
		env = simple_cd(env, str, &old_pwd, i);
	return (env);
}
