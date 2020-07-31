/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_new_strcpy(char *dest, char const *src)
{
	int i = 0;

	dest = malloc(sizeof(char) * my_strlen(dest) + 2);
	while (src[i] != '\0') {
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
	return (dest);
}
