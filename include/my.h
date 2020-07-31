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
int my_strlen(char const *str);
int my_putstr (char const *str);
char *my_strcpy (char * dest, char const *src);
char *my_strncpy (char *dest, char const *src, int n);
char *my_revstr (char *src);
char *my_strncat (char *dest, char const *src, int nb);
char *my_strdup (char const *src);
char *my_strcat (char *s1, char const *s2);
int my_getnbr(char *str);
unsigned int my_putunbr(unsigned int nb);
void my_putnbr_base(long int nb, char *base);
long int my_putlnbr(long int nb);
long long int my_putllnbr(long long int nb);
void my_printf(char const *str, ...);
char *my_read(char *path);
int my_strcmp(char const *str1, char const *str2);
char **str_to_array(char *str, char c);
int nombre_ligne(char *str, char c);
char *my_cutstr(char *str, int nb);
char *pur_str(char *str);
char *my_new_strcpy(char *dest, char const *src);
void my_swap(char **str1, char **str2);

#endif /* MY_H_ */
