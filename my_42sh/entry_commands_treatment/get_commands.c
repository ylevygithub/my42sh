/*
** EPITECH PROJECT, 2019
** get_commands.c
** File description:
** getting commands from stdin
*/

#include "../include/my.h"

char ***get_commands(char ***commands)
{
    char *entry;
    int validate = 0;

    do {
        display_prompt();
        if (getline(&entry, &(ssize_t){0}, stdin) == -1 || !entry) {
            my_putchar('\n');
            return (NULL);
        }
        entry[my_strlen(entry) - 1] = '\0';
        commands = free_commands(commands);
        if (commands = check_entry(commands, entry))
            validate++;
    } while (!validate);
    return (commands);
}

char ***free_commands(char ***commands)
{
    int indexY = 0;

    if (!commands)
        return (NULL);
    while (commands[indexY]) {
        for (int indexX = 0; commands[indexY][indexX]; indexX++)
            free(commands[indexY][indexX]);
        free(commands[indexY]);
        indexY++;
    }
    free(commands);
    return (NULL);
}

int check_last_operator(char ***commands)
{
    int index = 0;
    int check = 1;

    while (commands[index] && check)
        if (IS_OPERATOR(**commands[index]) && !commands[index + 1])
            check = 0;
        else
            index++;
    if (!check)
        switch (**commands[index]) {
            case '|':
            case '&': my_putstr_error("Invalid null command.\n");
            break;
            case '<':
            case '>': my_putstr_error("Missing name for redirect.\n");
            break;
            case ';': commands[index] = NULL;
                check = 1;
        }
    return (!check);
}

char ***check_entry(char ***commands, char *entry)
{
    int commandNb = 0;
    char *tmp = entry;

    if (!entry || !my_strlen(entry))
        return (NULL);
    entry = clean_str(entry);
    free(tmp);
    if ((commandNb = count_command_nb(entry)) == 0)
        return (NULL);
    commands = malloc(sizeof(char **) * (commandNb + 1));
    commands[commandNb] = NULL;
    parse_entry(entry, commands, commandNb);
    if (check_last_operator(commands) == 1)
        return (NULL);
    free(entry);
    return (commands);
}