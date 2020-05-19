/*
** EPITECH PROJECT, 2019
** my_shell.c
** File description:
** center of the minishell2
*/

#include "include/my.h"

int my_shell(t_node *envCpy)
{
    char ***commands = NULL;

    my_signal();
    for (;;) {
        if ((commands = get_commands(commands)) == NULL)
            return (0);
        set_executable_command(commands, envCpy);
        commands = free_commands(commands);
    }
    return (0);
}

void set_executable_command(char ***commands, t_node *envCpy)
{
    int run = 0;
    t_fds fds;

    for (int i = 0; !run && ((i > 0) ? commands[i - 1] : commands[i]);) {
        if (IS_OPERATOR(**commands[i]) && !i)
            i += 3;
        else
            run = execute_command(commands, &i, &fds, envCpy);
    }
}

int execute_command(char ***commands, int *index, t_fds *fds, t_node *envCpy)
{
    fds->rdMode = STANDART;
    fds->wrMode = STANDART;
    if (commands[*index + 1])
        return (execute_complex_command(commands, index, fds, envCpy));
    else {
        run_command(commands[*index], fds, envCpy);
        *index += 2;
    }
    return (0);
}

int execute_complex_command(
    char ***commands, int *index, t_fds *fds, t_node *envCpy)
{
    int addIndex = 0;
    int run = 0;

    while (!run && ((*index > 0) ? commands[*index - 1] : commands[*index]))
        if (commands[*index + 1] && **commands[*index + 1] != ';') {
            addIndex = operator_switch(commands, index, fds);
            run = check_fail(run_command(
                commands[*index], fds, envCpy), commands, *index);
            *index += addIndex + 2;
            addIndex = 0;
        }
        else {
            fds->rdMode = fds->wrMode;
            fds->wrMode = STANDART;
            run_command(commands[*index], fds, envCpy);
            fds->rdMode = STANDART;
            fds->wrMode = STANDART;
            *index += 2;
        }
    return (run);
}

int check_fail(int status, char ***commands, int index)
{
    if ((!strcmp(*commands[index + 1], "&&") && status == 84) ||
        (!strcmp(*commands[index + 1], "||") && status == 0))
        return (84);
    return (0);
}