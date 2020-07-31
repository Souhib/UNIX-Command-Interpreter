/*
** EPITECH PROJECT, 2018
** my_cutstr.c
** File description:
** my_cutstr.c
*/

#include <stdlib.h>
#include "my.h"

char *my_cutstr(char *str, int nb)
{
	int i = 0;
	char *newstr = malloc(sizeof(char) * my_strlen(str) + 1 - nb);

	while (str[nb] != '\0') {
		newstr[i] = str[nb];
		i = i + 1;
		nb = nb + 1;
	}
	newstr[i] = '\0';
	return (newstr);
}
