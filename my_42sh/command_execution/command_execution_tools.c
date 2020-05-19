/*
** EPITECH PROJECT, 2019
** basic_function_sec.c
** File description:
** basic functions
*/

#include "../include/my.h"

int check_parity(char *a, char *b, int toTheEnd)
{
    for (int i = 0; (toTheEnd) ? (a[i] && a[i] != ' ') || b[i] : b[i]; i++) {
        if (a[i] != b[i])
            return (0);
    }
    return (1);
}

char *str_join(char *str1, char *str2)
{
    char *result;
    int indexStr1 = 0;
    int indexStr2 = 0;

    while (str2[indexStr2] || str1[indexStr1]) {
        if (str1[indexStr1])
            indexStr1++;
        if (str2[indexStr2])
            indexStr2++;
    }
    result = malloc(indexStr1 + indexStr2 + 1);
    result[indexStr1 + indexStr2] = '\0';
    indexStr1 = -1;
    while (str1[++indexStr1])
        result[indexStr1] = str1[indexStr1];
    for (int index = 0; index < indexStr2; index++)
        result[indexStr1 + index] = str2[index];
    return (result);
}

char *tab_to_str(char **tab)
{
    int count = 0;
    int indexY = 0;
    int indexX = 0;
    int index = 0;
    char *result;

    for (int i = 0; tab[i]; i++)
        count += (i > 0) ? my_strlen(tab[i]) + 1 : my_strlen(tab[i]);
    result = malloc(count + 1);
    result[count] = '\0';
    while (tab[indexY]) {
        while (tab[indexY][indexX])
            result[index++] = tab[indexY][indexX++];
        if (index < count)
            result[index++] = ' ';
        indexY++;
        indexX = 0;
    }
    return (result);
}