/*
** EPITECH PROJECT, 2019
** entry_checking.c
** File description:
** checking entry before parsing
*/

#include "../include/my.h"

int count_command_nb(char *entry)
{
    int redundancy = 0;
    int result = 1;

    for (int index = 0; entry[index]; index++) {
        if (IS_OPERATOR(entry[index]))
            redundancy += (command_nb_operator(entry, index, &result)) ? 9 : 1;
        else {
            result += (redundancy) ? 1 : 0;
            redundancy = 0;
        }
        if (redundancy > 2 ||(entry[index] == ' ' &&
            IS_OPERATOR(entry[index - 1]) && IS_OPERATOR(entry[index + 1]))) {
            my_putstr_error("Error: syntax error arround '");
            my_putchar_error(entry[index]);
            my_putstr_error("'.\n");
            return (0);
        }
    }
    return (result);
}

int command_nb_operator(char *entry, int index, int *nb)
{
    char *c = entry + index;
    char *sign = "|;<>";

    if (!index && (*c == '|' || *c == ';'))
        return (84);
    for (int i = 0; sign[i]; i++)
        if ((*(c + 1) == sign[i] && sign[i] == *c && *c == ';') ||
            (*(c + 1) == sign[i] && (index) ? *(c - 1) == sign[i] : 0 &&
            sign[i] == *c && *c == '|') ||
            (*(c + 1) == sign[i] && (index) ? *(c - 1) == sign[i] : 0 &&
            sign[i] == *c && *c == '<') ||
            (*(c + 1) == sign[i] && (index) ? *(c - 1) == sign[i] : 0 &&
            sign[i] == *c && *c == '>') ||
            (*(c + 1) == sign[i] && sign[i] != *c))
            return (84);
    if (index && *c != *(c - 1))
        (*nb)++;
    return (0);
}