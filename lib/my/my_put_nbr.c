/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** puts a nb on stdout considering its base
*/

#include "my.h"

void my_put_nbr(const int nb, char const *base)
{
    static int len_base = -2;

    if (len_base == -2) {
        len_base = my_strlen(base);
        if (len_base <= 1)
            return;
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb, base);
    }
    if (nb >= len_base) {
        my_put_nbr(nb / len_base, base);
        my_put_nbr(nb % len_base, base);
    } else
        my_putchar(base[nb]);
}
