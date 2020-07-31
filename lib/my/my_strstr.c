/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** my_strstr.c
*/

char *my_strstr(const char *haystack, const char *needle)
{
	int i = 0;
	int j = 0;
	char *cmp = malloc(sizeof(char) * my_strlen(needle));

	while (haystack[i + j] != '\0') {
		while (i != my_strlen(needle)) {
			cmp[i] = haystack[i + j];
			i = i + 1;
		}
		cmp = '\0';
		if ((my_strcmp(cmp, needle)) == 0)
			return (cmp);
		else {
			j = j + 1;
			i = 0;
		}
	}
	return (NULL);
}
