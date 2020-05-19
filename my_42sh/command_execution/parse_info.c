/*
** EPITECH PROJECT, 2019
** parse_info.c
** File description:
** parse the command str to get the name and the args
*/

#include "../include/my.h"

char *get_function_name(char *entry)
{
    int index = -1;
    char *functionName;

    while (entry[++index] && entry[index] != ' ');
    functionName = malloc(index + 1);
    functionName[index] = '\0';
    index = 0;
    while (entry[index] && entry[index] != ' ')
        functionName[index++] = entry[index];
    return (functionName);
}

char **get_arg_name(char *entry)
{
    char **arg;
    int index = 0;
    int iArray = 0;

    if (!entry[0])
        return (NULL);
    arg = get_arg_name_malloc(entry, 0, 0);
    for (int line = 0; entry[index]; line++) {
        while (entry[index] != ' ' && entry[index]) {
            arg[line][iArray] = entry[index];
            iArray++;
            index++;
        }
        if (entry[index] == ' ')
            index++;
        iArray = 0;
    }
    return (arg);
}

char **get_arg_name_malloc(char *entry, int count, int index)
{
    char **arg;
    int lineCount = 0;

    for (int i = 0; entry[i]; i++)
        (entry[i] == ' ') ? lineCount++ : 1;
    arg = malloc(sizeof(char *) * (lineCount + 1 + 1));
    arg[lineCount + 1] = NULL;
    lineCount = 0;
    while (entry[index]) {
        while (entry[index] != ' ' && entry[index]) {
            count++;
            index++;
        }
        arg[lineCount] = malloc(count + 1);
        arg[lineCount][count] = '\0';
        count = 0;
        lineCount++;
        (entry[index] == ' ') ? index++ : 1;
    }
    return (arg);
}