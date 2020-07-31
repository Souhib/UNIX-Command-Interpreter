/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** my_strcat.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

char *my_strcat(char *s1, char const *s2)
{
	int i = 0;
	int j = 0;
	int nb = (my_strlen(s1) + my_strlen(s2)) + 2;
	char *output = malloc(sizeof(char) * nb);

	if (output == NULL)
		return (NULL);
	while (s1[i] != '\0') {
		output[j] = s1[i];
		i = i + 1;
		j = j + 1;
	}
	i = 0;
	while (s2[i] != '\0') {
		output[j] = s2[i];
		i = i + 1;
		j = j + 1;
	}
	output[j] = '\0';
	return (output);
}
