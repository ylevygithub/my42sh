/*
** EPITECH PROJECT, 2019
** command_treatment.c
** File description:
** command treatment
*/

#include "../include/my.h"

int treat_command(char *entry, t_node *envList)
{
    int result = 0;

    if (check_parity(entry, "cd", YES))
        result = my_cd(entry, envList);
    else if (check_parity(entry, "env", YES))
        result = my_env(envList);
    else
        result = treat_command_sec(entry, envList);
    return (result);
}

int treat_command_sec(char *entry, t_node *envList)
{
    int result = 0;

    if (check_parity(entry, "setenv", YES))
        result = my_setenv(envList, entry);
    else if (check_parity(entry, "unsetenv", YES))
        result = my_unsetenv(envList, entry);
    else
        result = treat_command_thd(entry, envList);
    return (result);
}

int treat_command_thd(char *entry, t_node *envList)
{
    int result = 0;

    if (check_parity(entry, "echo", YES))
        result = echo_command_center(entry);
    else if (check_parity(entry, "exit", YES))
        result = exit_value(entry, envList);
    else
        result = other_entry(entry, envList);
    return (result);
}

int exit_value(char *entry, t_node *envList)
{
    int index = -1;

    while (entry[++index] && entry[index] != ' ');
    if (!entry[index]) {
        free_linked_list(envList);
        my_putstr("exit\n");
        exit(0);
    }
    if (is_a_number(entry + index + 1)) {
        my_putstr("exit\n");
        exit(atoi(entry + index + 1));
    }
    return (84);
}

int other_entry(char *entry, t_node *envList)
{
    if (system_command(entry, envList) == 0) {
        my_putstr(entry);
        my_putstr(": Command not found.\n");
        return (84);
    }
    return (0);
}