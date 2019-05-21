/*
** EPITECH PROJECT, 2018
** exec_move
** File description:
** exec_move
*/

#include <curses.h>
#include <stdlib.h>
#include "../include/my_sokoban.h"

void exec_move_down(t_terminal_size *terminal, 
    t_map_info *info_map, t_free_case *case_info)
{
    clear();
    move_down(info_map, case_info);
    print_tab(info_map->map, line_size_tab(info_map->map), terminal);
    refresh();
}

void exec_move_up(t_terminal_size *terminal, 
    t_map_info *info_map, t_free_case *case_info)
{
    clear();
    move_up(info_map, case_info);
    print_tab(info_map->map, line_size_tab(info_map->map), terminal);
    refresh();
}

void exec_move_right(t_terminal_size *terminal, 
    t_map_info *info_map, t_free_case *case_info)
{
    clear();
    move_right(info_map, case_info);
    print_tab(info_map->map, line_size_tab(info_map->map), terminal);
    refresh();
}

void exec_move_left(t_terminal_size *terminal, 
    t_map_info *info_map, t_free_case *case_info)
{
    clear();
    move_left(info_map, case_info);
    print_tab(info_map->map, line_size_tab(info_map->map), terminal);
    refresh();
}

void reset_map(t_map_info *info_map, 
    t_terminal_size *terminal)
{
    my_free_tab(info_map->map);
    info_map->map = my_tabcpy(info_map->map_origin);
    info_map->x = info_map->x_origin;
    info_map->y = info_map->y_origin;
    clear();
    print_tab(info_map->map, line_size_tab(info_map->map), terminal);
    refresh();
}
