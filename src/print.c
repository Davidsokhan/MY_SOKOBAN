/*
** EPITECH PROJECT, 2018
** print
** File description:
** for print
*/

#include "../include/my_sokoban.h"
#include <curses.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int it = 0;

    while (str[it]) {
        my_putchar(str[it]);
        it++;
    }
}

void my_show_tab(char **tab)
{
    int it = 0;

    while (tab[it]) {
        my_putstr(tab[it]);
        my_putchar('\n');
        it++;
    }
}

void my_print_tab_window(t_terminal_size *terminal, t_map_info *info_map)
{
    clear();
    getmaxyx(stdscr, terminal->y, terminal->x);
    if (terminal->y - 5 < line_size_tab(info_map->map) || terminal->x - 5 < column_size_tab(info_map->map)) {
        clear();
        mvprintw(terminal->y/2, terminal->x/2, "too small window!");
        refresh();
    }
    else {
        set_terminal_info(terminal, info_map->map);
        print_tab(info_map->map, line_size_tab(info_map->map), terminal);
        refresh();
    }
}