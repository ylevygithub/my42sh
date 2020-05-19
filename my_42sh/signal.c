/*
** EPITECH PROJECT, 2019
** signal.c
** File description:
** signal handler
*/

#include "include/my.h"

void my_signal(void)
{
    signal(SIGINT, my_signal_sigint);
    signal(SIGSEGV, my_signal_sigsegv);
    signal(SIGFPE, my_signal_sigfpe);
}

void my_signal_sigint(int sig)
{
    my_putchar('\n');
    display_prompt();
}

void my_signal_sigsegv(int sig)
{
    my_putstr("Segmentation fault\n");
    exit(139);
}

void my_signal_sigfpe(int sig)
{
    my_putstr("Floating exception\n");
    exit(136);
}