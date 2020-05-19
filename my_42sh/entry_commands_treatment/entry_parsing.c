/*
** EPITECH PROJECT, 2019
** entry_parsing.c
** File description:
** parse the entry
*/

#include "../include/my.h"

void parse_entry(char *entry, char ***commands, int commandNb)
{
    char **commands_str = malloc(sizeof(char *) * (commandNb + 2));

    commands_str[commandNb] = NULL;
    commands_str[commandNb + 1] = NULL;
    parse_in_strings(entry, commands_str);
    for (int index = 0; commands_str[index]; index++) {
        commands[index] = str_to_tab(commands_str[index]);
        free(commands_str[index]);
    }
    free(commands_str[commandNb]);
    free(commands_str);
}

char **str_to_tab(char *str)
{
    char **tab = str_to_tab_malloc(str, tab);
    int indexY = 0;
    int indexX = 0;
    int i = 0;

    while (str[i]) {
        tab[indexY][indexX] = str[i];
        indexX++;
        i++;
        if (str[i] == ' ') {
            indexY++;
            indexX = 0;
            i++;
        }
    }
    return (tab);
}

char **str_to_tab_malloc(char *str, char **tab)
{
    int count = 1;
    int indexX = 0;
    int indexY = 0;
    int indexA = 0;

    for (int i = 0; str[i]; i++)
        (str[i] == ' ') ? count++ : 0;
    tab = malloc(sizeof(char *) * (count + 1));
    tab[count] = NULL;
    while (indexY < count) {
        while (str[indexA] && str[indexA] != ' ') {
            indexA++;
            indexX++;
        }
        tab[indexY] = malloc(indexX + 1);
        tab[indexY++][indexX] = '\0';
        indexX = 0;
        indexA++;
    }
    return (tab);
}

void parse_in_strings(char *entry, char **commands_str)
{
    int index = 0;
    int toggle = (IS_OPERATOR(entry[index])) ? 1 : 0;
    int detection = 0;
    char *tmp;

    for (int arrIndex = 0; entry[index]; arrIndex++) {
        tmp = command_dup_cut(entry + index);
        commands_str[arrIndex] = clean_str(tmp);
        free(tmp);
        detection = toggle;
        while (detection == toggle && entry[index]) {
            toggle = (IS_OPERATOR(entry[index])) ? 1 : 0;
            (toggle == detection) ? index++ : 0;
        }
    }
}

char *command_dup_cut(char *entry)
{
    int toggle = IS_OPERATOR(*entry) ? 1 : 0;
    int index = 0;
    int count = 0;
    char *result = 0;

    for (int stop = toggle; stop == toggle && entry[count];) {
        toggle = (IS_OPERATOR(entry[count])) ? 1 : 0;
        if (stop == toggle)
            count++;
    }
    result = malloc(count + 1);
    result[count] = '\0';
    while (index < count) {
        result[index] = entry[index];
        index++;
    }
    return (result);
}