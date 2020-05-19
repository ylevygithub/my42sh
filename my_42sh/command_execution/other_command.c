/*
** EPITECH PROJECT, 2019
** other_command.c
** File description:
** other command like ls ..
*/

#include "../include/my.h"

int system_command(char *entry, t_node *envList)
{
    int result = 0;
    char **pathList = get_path(envList);
    char **env = linked_list_to_array(envList);

    result = try_execute_command(entry, env, pathList);
    free_double_array(env);
    free_double_array(pathList);
    return (result);
}

void free_double_array(char **array)
{
    int index = 0;

    while (array[index])
        free(array[index++]);
    if (array)
        free(array);
}

int try_execute_command(char *entry, char **env, char **pathList)
{
    char *functionName = get_function_name(entry);
    char **arg = get_arg_name(entry);
    char *path[2];
    int result = 0;

    for (int index = 0; pathList[index]; index++) {
        path[0] = str_join(pathList[index], "/");
        path[1] = path[0];
        path[0] = str_join(path[0], functionName);
        free(path[1]);
        if (access(path[0], F_OK) == 0 && (result = 1))
            forking_execution(path[0], arg, env);
        free(path[0]);
    }
    if (access(entry, F_OK) == 0 && !result && (result = 1) &&
        (*entry == '/' || *entry == '.'))
        forking_execution(entry, arg, env);
    free(functionName);
    (arg) ? free_double_array(arg) : 1;
    return (result);
}

void forking_execution(char *path, char **arg, char **env)
{
    pid_t pid = fork();

    if (pid == 0) {
        execve(path, arg, env);
        kill(getpid(), SIGKILL);
    }
    if (pid > 0)
        wait(0);
}