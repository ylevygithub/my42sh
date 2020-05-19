/*
** EPITECH PROJECT, 2019
** my_cd_dash.c
** File description:
** my cd dash
*/

#include "../include/my.h"

int check_cd_dash(char *entry, int index, int *result, t_node *head)
{
    if (entry[index + 1] == '-' && !entry[index + 2]) {
        *result = my_cd_oldpwd_action(head);
        *result = (!(*result)) ? my_cd_oldpwd(head) : 84;
        *result = (!(*result)) ? my_cd_pwd(head) : 84;
        return (*result);
    }
    if (!entry[index]) {
        *result = my_cd_empty(head);
        *result = (!(*result)) ? my_cd_pwd(head) : 84;
        return (*result);
    }
    return (1);
}

int my_cd_oldpwd_action(t_node *head)
{
    t_node *traveler = head;

    while (traveler && !check_parity(traveler->str, "OLDPWD=", NO))
        traveler = traveler->next;
    if (traveler)
        chdir(traveler->str + 7);
    return (0);
}

char *check_cd_oldpwd(t_node *traveler, char *tmp)
{
    while (traveler && !check_parity(traveler->str, "PWD=", NO))
        traveler = traveler->next;
    if (traveler)
        tmp = my_strdup(traveler->str + 4);
    else {
        free(tmp);
        return (NULL);
    }
    return (tmp);
}

int my_cd_oldpwd(t_node *head)
{
    t_node *traveler = head;
    char *tmp;
    int search = 1;

    tmp = check_cd_oldpwd(traveler, tmp);
    if (tmp == NULL)
        return (84);
    while (traveler && search) {
        if (check_parity(traveler->str, "OLDPWD=", NO)) {
            free(traveler->str);
            traveler->str = str_join("OLDPWD=", tmp);
            search = 0;
        }
        traveler = traveler->next;
    }
    head = (search) ? linked_list_add(head, str_join("OLDPWD=", tmp)) : head;
    free(tmp);
    return (0);
}