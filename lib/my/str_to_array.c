/*
** EPITECH PROJECT, 2017
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static char **end_line(char **result, char *str, int *nb)
{
	result[nb[1]][nb[2]] = '\0';
	nb[1]++;
	result[nb[1]] = malloc(sizeof(char) * my_strlen(str) + 1);
	if (result[nb[1]] == NULL)
		return (NULL);
	nb[2] = 0;
	return (result);
}

int nombre_ligne(char *str, char c)
{
	int words = 1;

	for (int i = 0; str[i]; ++i) {
		if (str[i] == c)
			words++;
	}
	return (words);
}

char **str_to_array(char *str, char c)
{
	int nb[4] = {0, 0, 0, nombre_ligne(str, c)};
	char **result = malloc(sizeof(char *) * nb[3] + 2);

	if (result == NULL)
		return (NULL);
	result[0] = malloc(sizeof(char) * my_strlen(str) + 1);
	if (result[0] == NULL)
		return (NULL);
	while (str[nb[0]] != '\0') {
		if (str[nb[0]] != c) {
			result[nb[1]][nb[2]] = str[nb[0]];
			nb[2] = nb[2] + 1;
		}
		else
			end_line(result, str, nb);
		nb[0] = nb[0] + 1;
	}
	result[nb[1]][nb[2]] = '\0';
	return (result);
}
