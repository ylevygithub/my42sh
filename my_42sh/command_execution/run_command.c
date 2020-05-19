/*
** EPITECH PROJECT, 2019
** treat_command.c
** File description:
** treat the entry commands in terminal
*/

#include "../include/my.h"

int run_command(char **command, t_fds *fds, t_node *envList)
{
    int result = 0;
    char *commandLine;
    int saveIn = dup(STDIN_FILENO);
    int saveOut = dup(STDOUT_FILENO);

    pipe(fds->pfd);
    run_command_redirection(fds);
    commandLine = tab_to_str(command);
    result = treat_command(commandLine, envList);
    free(commandLine);
    if (fds->wrMode == PIPE)
        fds->tmpfd = dup(fds->pfd[PIPE_OUT]);
    run_command_close(fds, saveIn, saveOut);
    return (result);
}

void run_command_redirection(t_fds *fds)
{
    switch (fds->rdMode) {
        case PIPE: dup2(fds->tmpfd, STDIN_FILENO);
        break;
        case TXT: dup2(fds->tmpfd, STDIN_FILENO);
        break;
    }
    switch (fds->wrMode) {
        case PIPE: dup2(fds->pfd[PIPE_IN], STDOUT_FILENO);
        break;
        case TXT: dup2(fds->tmpfd, STDOUT_FILENO);
        break;
    }
}

void run_command_close(t_fds *fds, int saveIn, int saveOut)
{
    close(fds->pfd[PIPE_IN]);
    close(fds->pfd[PIPE_OUT]);
    dup2(saveIn, STDIN_FILENO);
    dup2(saveOut, STDOUT_FILENO);
    close(saveIn);
    close(saveOut);
}