/*
** EPITECH PROJECT, 2018
** struct_count
** File description:
** count for struct
*/

#include "../include/my_sokoban.h"

int count_free_case(char **map)
{
    int y = 0;
    int x = 0;
    int it = 0;

    while (map[y]) {
        while (map[y][x]) {
            if (map[y][x] == 'O')
                it++;
            x++;
        }
        y++;
        x = 0;
    }
    return (it);
}

int count_box(char **map)
{
    int y = 0;
    int x = 0;
    int it = 0;

    while (map[y]) {
        while (map[y][x]) {
            if (map[y][x] == 'X')
                it++;
            x++;
        }
        y++;
        x = 0;
    }
    return (it);
}
