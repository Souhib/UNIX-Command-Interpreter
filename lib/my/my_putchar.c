/*
** EPITECH PROJECT, 2017
** my_putchar.c
** File description:
** my_putchar.c
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char a)
{
	write (1, &a, 1);
}
