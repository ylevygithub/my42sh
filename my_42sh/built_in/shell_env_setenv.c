/*
** EPITECH PROJECT, 2019
** shell_env_sec.c
** File description:
** shell env functions 2
*/

#include "../include/my.h"

int my_env(t_node *head)
{
    t_node *traveler = head;

    while (traveler) {
        my_putstr(traveler->str);
        my_putchar('\n');
        traveler = traveler->next;
    }
    return (0);
}

int my_setenv(t_node *head, char *entry)
{
    int index = 0;
    int count = 0;
    char *arg1;
    char *arg2;

    for (count = 0; entry[index]; index++)
        if (entry[index] == ' ')
            count++;
    if (count >= 3) {
        my_putstr_error("setenv: too many arguments.\n");
        return (84);
    }
    arg1 = my_setenv_create_arg(entry + 7, 1);
    arg2 = my_setenv_create_arg(entry + 7, 2);
    if (check_setenv_syntax(arg1, arg2) == 84)
        return (84);
    my_setenv_sec(head, arg1, arg2);
    free(arg1);
    free(arg2);
    return (0);
}

void my_setenv_sec(t_node *head, char *arg1, char *arg2)
{
    t_node *traveler = head;
    int search = 1;
    while (traveler && search) {
        if (check_parity(traveler->str, arg1, NO)) {
            free(traveler->str);
            traveler->str = str_join(arg1, arg2);
            search = 0;
        }
        traveler = traveler->next;
    }
    if (search == 1)
        head = linked_list_add(head, str_join(arg1, arg2));
}

char *my_setenv_create_arg(char *args, int whichOne)
{
    int index = 0;
    int indexSave;
    int count = 0;
    char *tmp;
    char *result;

    while (whichOne == 2 && args[index] && args[index++] != ' ');
    indexSave = index;
    while (args[index] && args[index++] != ' ')
        count++;
    result = malloc(count + 1);
    result[count] = '\0';
    for (int i = 0; args[indexSave] && args[indexSave] != ' '; indexSave++)
        result[i++] = args[indexSave];
    if (whichOne == 1) {
        tmp = result;
        result = str_join(result, "=");
        free(tmp);
    }
    return (result);
}

int check_setenv_syntax(char *arg1, char *arg2)
{
    int index = 0;

    if (arg1[0] >= '0' && arg1[0] <= '9') {
        my_putstr("setenv: Variable name must ");
        my_putstr("begin with a letter.\n");
        return (84);
    }
    while (arg2[index]) {
        if (arg2[index] == '=') {
            my_putstr("setenv: Variable name must ");
            my_putstr("contain alphanumeric chatacters.\n");
            return (84);
        }
        index++;
    }
    return (0);
}