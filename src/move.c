/*
** EPITECH PROJECT, 2018
** move
** File description:
** move
*/

#include <curses.h>
#include <stdlib.h>
#include "../include/my_sokoban.h"

void replace_case_free(t_map_info *info_map, t_free_case *case_info)
{
    int x = 0;

    while (x < info_map->nbr_case) {
        if (info_map->map[case_info[x].y][case_info[x].x] != 'X')
            info_map->map[case_info[x].y][case_info[x].x] = 'O';
        x++;
    }
}

int move_down(t_map_info *info_map, t_free_case *case_info)
{
    if (info_map->map[info_map->y + 1][info_map->x] == '#')
        return (0);
    if (info_map->map[info_map->y + 1][info_map->x] == 'X') {
        if (info_map->map[info_map->y + 2][info_map->x] == '#')
            return (0);
        if (info_map->map[info_map->y + 2][info_map->x] == 'X')
            return (0);
        info_map->map[info_map->y][info_map->x] = ' ';
        info_map->map[info_map->y + 1][info_map->x] = 'P';
        info_map->map[info_map->y + 2][info_map->x] = 'X';
        info_map->y++;
        return (0);
    }
    info_map->map[info_map->y][info_map->x] = ' ';
    replace_case_free(info_map, case_info);
    info_map->map[info_map->y + 1][info_map->x] = 'P';
    info_map->y++;
    return (0);
}

int move_up(t_map_info *info_map, t_free_case *case_info)
{
    if (info_map->map[info_map->y - 1][info_map->x] == '#')
        return (0);
    if (info_map->map[info_map->y - 1][info_map->x] == 'X') {
        if (info_map->map[info_map->y - 2][info_map->x] == '#')
            return (0);
        if (info_map->map[info_map->y - 2][info_map->x] == 'X')
            return (0);
        info_map->map[info_map->y][info_map->x] = ' ';
        info_map->map[info_map->y - 1][info_map->x] = 'P';
        info_map->map[info_map->y - 2][info_map->x] = 'X';
        info_map->y--;
        return (0);
    }
    info_map->map[info_map->y][info_map->x] = ' ';
    replace_case_free(info_map, case_info);
    info_map->map[info_map->y - 1][info_map->x] = 'P';
    info_map->y--;
    return (0);
}

int move_right(t_map_info *info_map, t_free_case *case_info)
{
    if (info_map->map[info_map->y][info_map->x + 1] == '#')
        return (0);
    if (info_map->map[info_map->y][info_map->x + 1] == 'X') {
        if (info_map->map[info_map->y][info_map->x + 2] == '#')
            return (0);
        if (info_map->map[info_map->y][info_map->x + 2] == 'X')
            return (0);
        info_map->map[info_map->y][info_map->x] = ' ';
        info_map->map[info_map->y][info_map->x + 1] = 'P';
        info_map->map[info_map->y][info_map->x + 2] = 'X';
        info_map->x++;
        return (0);
    }
    info_map->map[info_map->y][info_map->x] = ' ';
    replace_case_free(info_map, case_info);
    info_map->map[info_map->y][info_map->x + 1] = 'P';
    info_map->x++;
    return (0);
}

int move_left(t_map_info *info_map, t_free_case *case_info)
{
    if (info_map->map[info_map->y][info_map->x - 1] == '#')
        return (0);
    if (info_map->map[info_map->y][info_map->x - 1] == 'X') {
        if (info_map->map[info_map->y][info_map->x - 2] == '#')
            return (0);
        if (info_map->map[info_map->y][info_map->x - 2] == 'X')
            return (0);
        info_map->map[info_map->y][info_map->x] = ' ';
        info_map->map[info_map->y][info_map->x - 1] = 'P';
        info_map->map[info_map->y][info_map->x - 2] = 'X';
        info_map->x--;
        return (0);
    }
    info_map->map[info_map->y][info_map->x] = ' ';
    replace_case_free(info_map, case_info);
    info_map->map[info_map->y][info_map->x - 1] = 'P';
    info_map->x--;
    return (0);
}