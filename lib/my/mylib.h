/*
** EPITECH PROJECT, 2023
** mylib.h
** File description:
** mylib.h
*/

#ifndef MYLIB
    #define MYLIB

int eflag(double flt, int counter);
int fflag(double flt, int counter);
int find_biggest_square(char **map, int lon, int lar, int ck);
void my_free_array(char **array);
int gflag(double flt, int counter);
int hexconv(unsigned int nb, int counter);
int maj_eflag(double flt, int counter);
int maj_gflag(double flt, int counter);
int majhexconv(unsigned int nb, int counter);
int my_atoi(char *str);
int my_printf(char *format, ...);
void my_putchar(char c);
int my_put_nbr(int nb, int counter);
int my_putstr(char const *str, int counter);
char **my_square_gen(int size, char *pattern);
void my_strcat(char *dest, const char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
unsigned long my_strlen(char const *str);
char **my_str_to_word_array(char *buffer, int tab_size, int cell_size);
int nfunc(char *str);
int octalconv(int nb, int counter);
int pconv(unsigned long int nb, int counter);
int uconv(unsigned long int nb, int counter);
int zer_add(long int tten, int counter);
char **str_to_array(char const *str);
char **col_str_to_array(char const *str);
int my_strncmp(char const *s1, char const *s2);
char **n_str_to_array(char const *str);
char **my_tabcpy(char ***tab2, int tablen);
char *my_strdup(char const *src);

#endif
