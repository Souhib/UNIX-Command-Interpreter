/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

static void string(char const *str, int i, va_list ap, ...)
{
	switch (str[i + 1]) {
	case 'c':
		my_putchar(va_arg(ap, int));
		break;
	case 's':
		my_putstr(va_arg(ap, char *));
		break;
	}
}

static void number(char const *str, int i, va_list ap, ...)
{
	switch (str[i + 1]) {
	case 'd':
		my_putnbr(va_arg(ap, int));
		break;
	case 'i':
		my_putnbr(va_arg(ap, int));
		break;
	case 'u':
		my_putunbr(va_arg(ap, unsigned int));
		break;
	case '%':
		my_putchar('%');
		break;
	}
}

static void flag (char const *str, int i, va_list ap, ...)
{
	while (str[i] != '\0') {
		if (str[i] == '%') {
			if (str[i + 1] == 's' || str[i + 1] == 'c')
				string(str, i, ap);
			if (str[i + 1] == 'd' || str[i + 1] == 'i' ||
			str[i + 1] == 'u' || str[i + 1] == '%')
				number(str, i, ap);
			i = i + 1;
		}
		else {
			my_putchar(str[i]);
		}
		i = i + 1;
	}
}

void my_printf(char const *str, ...)
{
	int i = 0;
	va_list ap;

	va_start(ap, *str);
	flag(str, i, ap);
	va_end(ap);
}
