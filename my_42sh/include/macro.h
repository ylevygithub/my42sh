/*
** EPITECH PROJECT, 2018
** macro.h
** File description:
** macro for my_runner
*/

#ifndef __MACRO_H__
#define __MACRO_H__
#include "my.h"

#define IS_OPERATOR(c) ((c) == '|' || (c) == '<' || \
    (c) == '>' || (c) == ';' || (c) == '&')
#define PIPE_IN 1
#define PIPE_OUT 0
#define YES 1
#define NO 0
#define ON 1
#define OFF 0
#define E 2
#define e 1

typedef enum e_rwMode
{
    STANDART,
    PIPE,
    TXT
} e_rwMode;

#endif