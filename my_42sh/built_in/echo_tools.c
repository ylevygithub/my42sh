/*
** EPITECH PROJECT, 2019
** eco_tools
** File description:
** echo_tools
*/

#include "../include/my.h"

int nbr_of_arg(char *str)
{
    int index = 0;
    int space = 0;

    while (str[index] != '\0') {
        if (str[index] == ' ')
            space++;
        index++;
    }
    return (space);
}

int strlen_to_space(char *str)
{
    int index = -1;

    while (str[++index] && str[index] != ' ');
    return (index);
}

char *my_strcpy(char *src)
{
    int index = 0;
    char *dest = malloc(sizeof(char) * (strlen_to_space(src) + 1));

    dest[strlen_to_space(src)] = '\0';
    while (src[index] != '\0') {
        if (src[index] == ' ')
            return (dest);
        dest[index] = src[index];
        index++;
    }
    return (dest);
}

char *adress_move(char *str)
{
    while (*str != '\0') {
        if (*str == ' ') {
            str++;
            return (str);
        }
        str++;
    }
    str++;
    return (str);
}

int check_switches(t_echo *echo, int line, int point)
{
    switch(echo->input[line][point]) {
        case 'e':
            echo->flag.flag_e = 1;
            echo->flag.last = e;
            break;
        case 'E':
            echo->flag.flag_E = 1;
            echo->flag.last = E;
            break;
        case 'n':
            echo->flag.flag_n = 1;
            break;
    }
}