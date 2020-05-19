/*
** EPITECH PROJECT, 2019
** my_cd.c
** File description:
** my_cd
*/

#include "../include/my.h"

int my_cd(char *entry, t_node *head)
{
    int index = -1;
    int check = 0;
    int result = 0;

    while (entry[++index] && entry[index] != ' ');
    if (check_cd_dash(entry, index, &result, head) != 1)
        return (result);
    while (entry[++index] && !check)
        check = (entry[index] == ' ') ? 1 : 0;
    if (!check)
        result = my_cd_action(entry + 3, head);
    else {
        my_putstr_error("cd: too many arguments.\n");
        return (84);
    }
    my_cd_pwd(head);
    return (result);
}

int my_cd_empty(t_node *head)
{
    t_node *traveler = head;

    while (traveler && !check_parity(traveler->str, "HOME=", NO))
        traveler = traveler->next;
    if (traveler)
        chdir(traveler->str + 5);
    return (0);
}

int my_cd_action(char *path, t_node *head)
{
    DIR *dir;

    if (access(path, F_OK) == 0) {
        my_cd_oldpwd(head);
        dir = opendir(path);
        (dir) ? chdir(path) : my_putstr_error(path);
        (dir) ? closedir(dir) : my_putstr_error(": Not a directory.\n");
    }
    else {
        my_putstr_error(path);
        my_putstr_error(": No such file or directory.\n");
        return (84);
    }
    return (0);
}

int my_cd_pwd(t_node *head)
{
    t_node *traveler = head;
    char cwd[256];
    int search = 1;

    getcwd(cwd, 256);
    while (traveler && search) {
        if (check_parity(traveler->str, "PWD=", NO)) {
            free(traveler->str);
            traveler->str = str_join("PWD=", cwd);
            search = 0;
        }
        traveler = traveler->next;
    }
    if (search == 1)
        head = linked_list_add(head, str_join("PWD=", cwd));
    return (0);
}