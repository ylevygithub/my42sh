/*
** EPITECH PROJECT, 2019
** linked_list.c
** File description:
** linked_list gestion
*/

#include "../include/my.h"

t_node *linked_list_store(char **dubArray)
{
    t_node *head = NULL;

    for (int index = 0; dubArray[index]; index++)
        head = linked_list_add(head, my_strdup(dubArray[index]));
    return (head);
}

t_node *linked_list_add(t_node *head, char *str)
{
    t_node *traveler;
    t_node *tmp = malloc(sizeof(t_node));

    tmp->str = str;
    tmp->next = NULL;
    if (head == NULL)
        head = tmp;
    else {
        traveler = head;
        while (traveler->next != NULL)
            traveler = traveler->next;
        traveler->next = tmp;
    }
    return (head);
}

void free_linked_list(t_node *head)
{
    t_node *tmp;

    while (head) {
        tmp = head->next;
        if (head->str)
            free(head->str);
        free(head);
        head = tmp;
    }
}

char **linked_list_to_array(t_node *head)
{
    t_node *traveler = head;
    char **array;
    int count = 0;

    while (traveler) {
        count++;
        traveler = traveler->next;
    }
    array = malloc(sizeof(char *) * (count + 1));
    array[count] = NULL;
    traveler = head;
    for (int index = 0; traveler; index++) {
        array[index] = my_strdup(traveler->str);
        traveler = traveler->next;
    }
    return (array);
}