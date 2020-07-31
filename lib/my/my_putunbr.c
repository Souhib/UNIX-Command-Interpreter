/*
** EPITECH PROJECT, 2017
** my_putunbr.c
** File description:
** my_putunbr.c
*/

#include <unistd.h>
#include "my.h"

unsigned int my_putunbr(unsigned int nb)
{
	if (nb > 9)
		my_putnbr(nb / 10);
	my_putchar(nb % 10 + '0');
}
