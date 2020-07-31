/*
** EPITECH PROJECT, 2018
** pur_str.c
** File description:
** pur_str.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *clean_str(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == '\t')
			str[i] = ' ';
		i = i + 1;
	}
	return (str);
}

char *pur_str(char *str)
{
	int i = 0;
	int e = 0;

	str = clean_str(str);
	while (str[i] == ' ')
		i = i + 1;
	while (str[i] != '\0') {
		if ((str[i] != ' ' || str[i + 1] != ' ') &&
			(str[i] != ' ' || str[i + 1] != '\0')) {
			str[e] = str[i];
			e = e + 1;
			i = i + 1;
		}
		else
			i = i + 1;
	}
	str[e] = '\0';
	return (str);
}
