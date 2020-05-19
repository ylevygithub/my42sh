/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo
*/

#include "../include/my.h"

int print_hub(t_echo *echo)
{
    int index = 0;

    while (index < echo->nbr_of_arg) {
        echo->quotes = OFF;
        check_quotes(echo, index);
        if (echo->input[index][0] != '-')
            print(echo, index);
        index++;
    }
}

int set_switches_two(t_echo *echo, int line)
{
    int point = 0;
    int index = 0;

    while (echo->input[line][point] != '\0') {
        if (echo->input[line][0] == '-' &&
            echo->input[line][strlen(echo->input[line]) - 1]
            != 'n' && index == 0) {
            my_putstr(echo->input[line]);
            my_putchar(' ');
            index++;
        }
        if (echo->input[line][0] == '-' && point >= 1)
            check_switches(echo, line , point);
        point++;
    }
}

int set_switches(t_echo *echo)
{
    int line = 0;

    while (echo->input[line] != NULL) {
        set_switches_two(echo, line);
        line++;
    }
    print_hub(echo);
}

void set_value(t_echo *echo, char *str)
{
    echo->flag.flag_e = 0;
    echo->flag.flag_E = 0;
    echo->flag.flag_n = 0;
    echo->nbr_of_arg = nbr_of_arg(str);
    echo->input = malloc(sizeof(char *) * (echo->nbr_of_arg + 1));
    echo->input[echo->nbr_of_arg] = NULL;
}

int echo_command_center(char *str)
{
    int index = 0;

    t_echo *echo = malloc(sizeof(t_echo));
    set_value(echo, str);
    if (echo->nbr_of_arg == 0) {
        my_putchar('\n');
        return (0);
    }
    while (index < echo->nbr_of_arg) {
        str = adress_move(str);
        echo->input[index] = my_strcpy(str);
        index++;
    }
    set_switches(echo);
    for (int index = 0; index < echo->nbr_of_arg + 1; index++)
        free(echo->input[index]);
    free(echo->input);
    free(echo);
    return (0);
}