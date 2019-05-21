/*
** EPITECH PROJECT, 2018
** set_struct
** File description:
** set the stucts
*/

#include "../include/my_sokoban.h"
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

t_info_box *set_struct_box(char **map)
{
    int y = 0;
    int x = 0;
    int it = 0;
    t_info_box *info = malloc(sizeof(t_info_box) * count_box(map));

    while (map[y]) {
        while (map[y][x]) {
            if (map[y][x] == 'X') {
                info[it].y = y;
                info[it].x = x;
                it++;
            }
            x++;
        }
        y++;
        x = 0;
    }
    return (info);
}

void set_map_info(t_map_info *info_map, char **map)
{
    int x = 0;
    int y = 0;

    info_map->map = my_tabcpy(map);
    info_map->map_origin = my_tabcpy(map);
    info_map->line_size = line_size_tab(map);
    info_map->column_size = column_size_tab(map);
    while (map[y]) {
        while (map[y][x]) {
            if (map[y][x] == 'P') {
                info_map->x = x;
                info_map->y = y; 
            }
            x++;
        }
        y++;
        x = 0;
    }
    info_map->x_origin = info_map->x;
    info_map->y_origin = info_map->y;
    info_map->nbr_case = count_free_case(map);
    my_free_tab(map);
}

void set_terminal_info(t_terminal_size *terminal, char **map)
{
    terminal->y = (terminal->y / 2) - (column_size_tab(map) / 2);
    terminal->x = (terminal->x / 2) - (line_size_tab(map) / 2);
    terminal->save_x = terminal->x;
    terminal->save_y = terminal->y;
}

t_free_case *set_free_case_info(char **map)
{
    t_free_case *info = malloc(sizeof(t_free_case) * count_free_case(map));
    int y = 0;
    int x = 0;
    int it = 0;

    while (map[y]) {
        while (map[y][x]) {
            if (map[y][x] == 'O') {
                info[it].y = y;
                info[it].x = x;
                it++;
            }
            x++;
        }
        y++;
        x = 0;
    }
    return (info);
}
