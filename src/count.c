/*
** EPITECH PROJECT, 2018
** count
** File description:
** count
*/

#include "../include/my_sokoban.h"

int column_size(char *str)
{
    int it = 0;

    while (str[it] != '\n')
        it++;
    return (it);
}

int line_size(char *str)
{
    int it = 0;
    int count = 0;

    while (str[it] != '\0') {
        if (str[it] == '\n')
            count++;
        it++;
    }
    return (count);
}

int line_size_tab(char **tab)
{
    int it = 0;

    while (tab[it])
        it++;
    return (it);
}

int column_size_tab(char **tab)
{
    int it = 0;

    while (tab[0][it])
        it++;
    return (it);
}