/*
** EPITECH PROJECT, 2019
** path.c
** File description:
** path handling
*/

#include "../include/my.h"

char **get_path(t_node *envList)
{
    char **result;
    t_node *traveler = envList;
    int index = 0;

    while (traveler && !check_parity(traveler->str, "PATH=", NO))
        traveler = traveler->next;
    result = malloc_path(traveler->str);
    while (traveler->str[index++] != '=');
    result = str_to_arr(traveler->str, index, result);
    return (result);
}

char **str_to_arr(char *str, int start, char **result)
{
    int index = 0;
    int line = 0;

    while (result[line]) {
        while (str[start] != ':' && str[start]) {
            result[line][index] = str[start];
            index++;
            start++;
        }
        start++;
        line++;
        index = 0;
    }
    return (result);
}

char **malloc_path(char *path)
{
    char **result;
    int prePath = 0;
    int index = 0;
    int pathNb = path_nb(path);

    result = malloc(sizeof(char *) * (pathNb + 1));
    result[pathNb] = NULL;
    while (path[prePath++] != '=');
    for (int line = 0; line < pathNb; line++) {
        while (path[prePath + index] != ':' && path[prePath + index])
            index++;
        result[line] = malloc(index + 1);
        result[line][index] = '\0';
        prePath = prePath + index + 1;
        index = 0;
    }
    return (result);
}

int path_nb(char *str)
{
    int count = 1;
    for (int index = 0; str[index]; index++)
        if (str[index] == ':')
            count++;
    return (count);
}