/*
** EPITECH PROJECT, 2017
** getnbr.c
** File description:
** getnbr
*/

int my_getnbr(char *str)
{
	int nb = 0;
	int isneg = 1;
	int i = 0;

	while (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-')
			isneg = isneg * -1;
		i = i + 1;
	}
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			nb = nb * 10;
			nb = nb + str[i] - '0';
			i = i + 1;
		}
		else
			i = i + 1;
	}
	return (nb * isneg);
}
