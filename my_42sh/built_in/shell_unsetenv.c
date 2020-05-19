/*
** EPITECH PROJECT, 2019
** shell_env.c
** File description:
** shell environnement function (setenv/unsetenv/env)
*/

#include "../include/my.h"

int my_unsetenv_check(char *entry, t_node *traveler, char **arg)
{
    if (entry[8]) {
        my_unsetenv_sec(traveler, traveler, arg);
        free_double_array(arg);
    }
    else {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return (84);
    }
    return (0);
}

int my_unsetenv(t_node *head, char *entry)
{
    t_node *traveler;
    t_node *tmp;
    char **arg = (entry[8]) ? my_unsetenv_get_arg(entry + 9) : NULL;

    for (int index = 0; entry[8] && arg[index]; index++) {
        traveler = head;
        if (check_parity(traveler->str, arg[index], NO)) {
            free(traveler->str);
            traveler->str = traveler->next->str;
            tmp = traveler->next;
            traveler->next = traveler->next->next;
            free(tmp);
        }
    }

    if (my_unsetenv_check(entry, traveler, arg) == 84)
        return (84);
    head = verify_path_existance(head);
    return (0);
}

void my_unsetenv_sec(t_node *trav, t_node *travSave, char **arg)
{
    t_node *tmp;

    for (int i = 0; arg[i]; i++) {
        while (trav->next && !check_parity(trav->next->str, arg[i], NO)) {
            tmp = trav;
            trav = trav->next;
        }
        if (trav->next) {
            tmp = trav->next;
            trav->next = trav->next->next;
            free(tmp->str);
            free(tmp);
        }
        if (!trav->next && check_parity(trav->str, arg[i], NO)) {
            free(trav->str);
            free(trav);
            tmp->next = NULL;
        }
        trav = travSave;
    }
}

char **my_unsetenv_get_arg(char *argStr)
{
    char *tmp;
    char **argArr = get_arg_name(argStr);

    for (int index = 0; argArr[index]; index++) {
        tmp = argArr[index];
        argArr[index] = str_join(argArr[index], "=");
        free(tmp);
    }
    return (argArr);
}

t_node *verify_path_existance(t_node *head)
{
    t_node *traveler = head;
    int check = 0;

    while (traveler && !check) {
        if (check_parity(traveler->str, "PATH=", NO))
            check++;
        traveler = traveler->next;
    }
    if (!check)
        my_setenv(head, "setenv PATH /bin");
}