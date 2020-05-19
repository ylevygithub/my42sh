/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main of minishell2
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    t_node *envCopy;

    if (ac != 1) {
        my_putstr_error("Error: No arguments needed.\n");
        return (84);
    }
    envCopy = linked_list_store(env);
    if (my_shell(envCopy) == 84)
        return (84);
    free_linked_list(envCopy);
    return (0);
}