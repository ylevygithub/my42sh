/*
** EPITECH PROJECT, 2018
** structure.h
** File description:
** structure for my_runner
*/

#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__
#include "my.h"

typedef struct s_node
{
    char *str;
    struct s_node *next;
} t_node;

typedef struct f_flags
{
    int flag_E;
    int flag_e;
    int flag_n;
    int last;
} t_flags;

typedef struct e_echo
{
    int nbr_of_arg;
    int quotes;
    char **input;
    t_flags flag;
} t_echo;

typedef struct s_fds
{
    int pfd[2];
    e_rwMode rdMode;
    e_rwMode wrMode;
    int tmpfd;
} t_fds;

#endif