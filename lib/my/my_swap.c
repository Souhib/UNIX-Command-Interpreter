/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** my_swap.c
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void my_swap(char **str1, char **str2)
{
	char *str = malloc(sizeof(char));

	str = my_new_strcpy(str, *str1);
	*str1 = my_new_strcpy(*str1, *str2);
	*str2 = my_new_strcpy(*str2, str);
}
