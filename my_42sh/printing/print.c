/*
** EPITECH PROJECT, 2019
** print.c
** File description:
** all basic printing functions
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr(char const *str)
{
    int index = -1;

    while (str[++index]);
    write(1, str, index);
}

void my_putstr_error(char const *str)
{
    int index = -1;

    while (str[++index]);
    write(2, str, index);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    if (nb > 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}