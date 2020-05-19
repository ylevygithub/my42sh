/*
** EPITECH PROJECT, 2019
** redirect_commands.c
** File description:
** redirection of command operator
*/

#include "../include/my.h"

int operator_switch(char ***commands, int *index, t_fds *fds)
{
    int addIndex = 0;

    switch (**commands[*index + 1]) {
        case '|':
        if (commands[*index + 1][0][1] == '\0')
            pipe_operator(fds);
        break;
        case '>': addIndex = greater_than_operator(commands, index, fds);
        break;
        case '<': addIndex = less_than_operator(commands, index, fds);
    }
    return (addIndex);
}

void pipe_operator(t_fds *fds)
{
    if (fds->wrMode == STANDART) {
        fds->rdMode = STANDART;
        fds->wrMode = PIPE;
    }
    else {
        fds->rdMode = PIPE;
        fds->wrMode = PIPE;
    }
}

int greater_than_operator(char ***commands, int *index, t_fds *fds)
{
    int addIndex = 0;
    int fd;

    while (commands[*index + 1 + addIndex] &&
        **commands[*index + 1 + addIndex] == '>') {
        if (addIndex)
            close(fd);
        addIndex += 2;
        if (commands[*index - 1 + addIndex][0][1] == '>')
            fd = open(*commands[*index + addIndex],
                O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
        else
            fd = open(*commands[*index + addIndex],
                O_CREAT | O_WRONLY, S_IRWXU);
    }
    greater_than_operator_set_fd(fds, fd);
    return (addIndex);
}

void greater_than_operator_set_fd(t_fds *fds, int fd)
{
    if (fds->wrMode == PIPE)
        fds->rdMode = PIPE;
    else {
        fds->rdMode = STANDART;
        fds->tmpfd = fd;
    }
    fds->wrMode = TXT;
}

int less_than_operator(char ***commands, int *index, t_fds *fds)
{
    int addIndex = 2;
    if (commands[*index + 1][0][1] == '<');
    else {
        fds->rdMode = TXT;
        fds->wrMode = STANDART;
        fds->tmpfd = open(*commands[*index + 2], O_RDONLY, S_IRWXU);
    }
    return (addIndex);
}