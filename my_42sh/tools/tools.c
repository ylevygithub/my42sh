/*
** EPITECH PROJECT, 2019
** tools.c
** File description:
** tools for minishell2
*/

#include "../include/my.h"

int str_to_int(char *str)
{
    int number = 0;
    int index = 0;
    int isNeg = 0;

    if (str[0] == '-') {
        isNeg = 1;
        index++;
    }
    while (str[index] >=  '0' && str[index] <= '9') {
        number += str[index] - 48;
        if (str[++index])
            number *= 10;
    }
    return (isNeg == 1 ? number *= -1 : number);
}

int is_a_number(char *str)
{
    int index = 0;

    if (str[index] && str[index] == '-')
        index++;
    for (; str[index]; index++)
        if (str[index] < '0' || str[index] > '9')
            return (0);
    return (1);
}