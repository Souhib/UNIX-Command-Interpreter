/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

void my_putchar (char a);
int my_isneg (int nb);
int my_putnbr(int nb);
unsigned int my_putunbr(unsigned int nb);
int my_strlen(char const *str);
void my_putstr (char const *str);
char *my_strcpy (char * dest, char const *src);
char *my_strncpy (char *dest, char const *src, int n);
char *my_revstr (char *src);
char *my_strcat (char *s1, char *s2);
char *my_strncat (char *dest, char const *src, int nb);
char *my_strdup (char const *src);
int my_getnbr(char *str);
int sorted(int *array, int size);
int my_strcmp(char const str1, char const str2);
void my_printf(char const *str, ...);
char *my_read(char *path);
char *pur_str(char *str);
int nombre_ligne(char *str, char c);
char **str_to_array(char *str, char c);
void my_swap(char **str1, char **str2);
char *my_new_strcpy(char *dest, char const *src);

#endif /* MY_H_ */
