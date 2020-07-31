/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../../include/my.h"

int my_strcmp(char const *str1, char const *str2)
{
	int i = 0;
	int j = 0;

	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] < str2[i]) {
			j = str1[i] - str2[i];
			return (j);
		}
		else if (str1[i] > str2[i]) {
			j = str1[i] + str2[i];
			return (j);
		}
		else
			i = i + 1;
	}
	return (0);
}
