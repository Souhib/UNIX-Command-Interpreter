/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** my_putnbr_base.c
*/

#include <unistd.h>
#include "my.h"

void my_putnbr_base(long int nb, char *base)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb >= my_strlen(base)) {
		my_putnbr_base(nb / my_strlen(base), base);
	}
	my_putchar(base[nb % my_strlen(base)]);
}
