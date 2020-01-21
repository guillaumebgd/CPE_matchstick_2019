/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2020
** File description:
** header for libmy
*/

#ifndef MY_H_

#define MY_H_

//returns 84 if write error
int my_putchar(const char c);
//returns -1 if error
int my_strlen(const char *str);
//returns 84 if write error
int my_putstr(const int fd, char const *str);

//returns 0 if error
int my_getnbr(const char *str);
//doesn't write if error
void my_put_nbr(const int nb, char const *base);

//returns 1 if c is a number, otherwise, returns 0
int my_isnum(const char c);

//returns max if error
int my_rand(const int min, const int max);

//returns NULL if EoF or nothing to read or error
char *get_next_line(const int fd, const int nb_bytes);

#endif /* MY_H_ */