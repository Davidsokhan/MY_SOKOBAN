/*
** EPITECH PROJECT, 2018
** game_end
** File description:
** end of the game
*/

#include "../include/my_sokoban.h"
#include <curses.h>
#include <stdlib.h>

int loose_case(t_map_info *info_map, char **map, int x, t_free_case *case_info)
{
    int it = 0;
    t_info_box *box = set_struct_box(info_map->map);

    while (it < info_map->nbr_case) {
        if (box[x].x == case_info[it].x && box[x].y == case_info[it].y)
            return (1);
        it++;
    }
    if ((map[box[x].y - 1][box[x].x] == '#' 
    	|| map[box[x].y - 1][box[x].x] == 'X') &&
     (map[box[x].y][box[x].x + 1] == '#' 
     	|| map[box[x].y][box[x].x + 1] == 'X')) {
        return (1);
    }
    if ((map[box[x].y - 1][box[x].x] == '#' 
    	|| map[box[x].y - 1][box[x].x] == 'X') &&
     (map[box[x].y][box[x].x - 1] == '#' 
     	|| map[box[x].y][box[x].x - 1] == 'X')) {
        return (1);
    }
    if ((map[box[x].y + 1][box[x].x] == '#' 
    	|| map[box[x].y + 1][box[x].x] == 'X') &&
     (map[box[x].y][box[x].x - 1] == '#' 
     	|| map[box[x].y][box[x].x - 1] == 'X')) {
        return (1);
    }
    if ((map[box[x].y + 1][box[x].x] == '#' 
    	|| map[box[x].y + 1][box[x].x] == 'X') &&
     (map[box[x].y][box[x].x + 1] == '#' 
     	|| map[box[x].y][box[x].x + 1] == 'X')) {
        return (1);
    }
    return (0);
}

int you_loose(t_map_info *info_map ,t_free_case *case_info)
{
    int x = 0;
    int it = 0;

    while (x < count_box(info_map->map)) {
            if (loose_case(info_map, info_map->map, x, case_info) == 1)
                it++;
            x++;
    }
    if (it == count_box(info_map->map)) {
    	//my_free_tab(info_map->map);
        //my_free_tab(info_map->map_origin);
        return (1);
    }
    return (0);
}

int end_game(t_map_info *info_map, t_free_case *case_info)
{
    int it = 0;
    int x = 0;

    while (x < info_map->nbr_case) {
        if (info_map->map[case_info[x].y][case_info[x].x] == 'P') {
            it++;
            return (0);
        }
        x++;
    }
    if (count_free_case(info_map->map) == 0 && it == 0) {
        endwin();
        my_putstr("you win\n");
        return (1);
    }
    if (you_loose(info_map, case_info) == 1) {
        endwin();
        my_putstr("you loose!\n");
        return (2);
    }
    return (0);
}
