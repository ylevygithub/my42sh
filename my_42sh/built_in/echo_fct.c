/*
** EPITECH PROJECT, 2019
** echo_fct
** File description:
** echo_fct
*/

#include "../include/my.h"

int switch_print_reverse(char a)
{
    switch(a) {
        case 'a': my_putchar('\a');
        break;
        case 'b': my_putchar('\b');
        break;
        case 't': my_putchar('\t');
        break;
        case 'n': my_putchar('\n');
        break;
        case 'v': my_putchar('\v');
        break;
        case 'f': my_putchar('\f');
        break;
        case 'r': my_putchar('\r');
        break;
    }
}

int finale(t_echo *echo)
{
    if (echo->flag.flag_n == ON)
        return (0);
    else
        my_putchar('\n');
    return (0);
}

int print(t_echo *echo, int line)
{
    for (int index = 0; echo->input[line][index] != '\0'; index++) {
        if (echo->quotes == OFF && echo->input[line][index] == '\\') {
            index++;
            my_putchar(echo->input[line][index]);
        }
        else if (echo->input[line][index] == '\\') {
            switch_print_reverse(echo->input[line][index + 1]);
            index++;
        }
        else if (echo->input[line][index] != '"')
            my_putchar(echo->input[line][index]);
    }
    return (finale(echo));
}

int check_quotes(t_echo *echo, int index)
{
    if (echo->input[index][0] == '"')
        echo->quotes = ON;
}