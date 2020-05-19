/*
** EPITECH PROJECT, 2019
** str_tools.c
** File description:
** tools for strings
*/

#include "../include/my.h"

char *my_strdup(char *str)
{
    char *result;
    int index = -1;

    while (str[++index]);
    result = malloc(index + 1);
    if (!result)
        return (NULL);
    result[index] = '\0';
    index = -1;
    while (str[++index])
        result[index] = str[index];
    return (result);
}

int my_strlen(char *str)
{
    int index = -1;

    while (str[++index]);
    return (index);
}

char *clean_str(char *str)
{
    char *result;
    int mallocCount = 0;
    int index = -1;

    while (str[++index] == ' ' || str[index] == '\t');
    mallocCount = clean_str_count_malloc(str, index);
    result = malloc(mallocCount + 1);
    result[mallocCount] = '\0';
    mallocCount = 0;
    for (int i = index; str[i]; i++)
        if ((str[i] != ' ' && str[i] != '\t') ||
            ((str[i] == ' ' || str[i] == '\t') && ((str[i + 1] != ' ' &&
                str[i + 1] != '\t') && str[i + 1])))
            result[mallocCount++] = (str[i] == '\t') ? ' ' : str[i];
    return (result);
}

int clean_str_count_malloc(char *str, int index)
{
    int count = 0;

    while (str[index]) {
        if (str[index] != ' ' && str[index] != '\t')
            count++;
        else
            ((str[index + 1] != ' ' && str[index + 1] != '\t') &&
                str[index + 1]) ? count++ : 1;
        index++;
    }
    return (count);
}