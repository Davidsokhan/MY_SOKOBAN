/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** my_sokoban
*/

#include <curses.h>
#include <stdlib.h>
#include "../include/my_sokoban.h"

void print_tab(char **map, int line_size, t_terminal_size *terminal)
{
    int x = 0;

    while (x < line_size) {
        mvprintw(terminal->y, terminal->x, map[x]);
        terminal->y = terminal->y + 1;
        x++;
    }
    terminal->y = terminal->save_y;
}

char **my_tabcpy(char **map)
{
    int y = 0;
    int x = 0;
    char **tab = malloc(sizeof(char *) * (line_size_tab(map) + 1));

    while (map[y]) {
        tab[y] = malloc(sizeof(char) * (column_size_tab(map) + 1));
        while (map[y][x]) {
            tab[y][x] = map[y][x];
            x++;
        }
        tab[y][x] = '\0';
        y++;
        x = 0;
    }
    tab[y] = NULL;
    return (tab);
}

int my_sokoban(char **map)
{
    t_terminal_size *terminal = malloc(sizeof(t_terminal_size));
    t_map_info *info_map = malloc(sizeof(t_map_info));
    t_free_case *case_info = set_free_case_info(map);
    int ch = getch();
    int end = 0;

    initscr();
    keypad(stdscr, 1);
    getmaxyx(stdscr, terminal->y, terminal->x);
    set_terminal_info(terminal, map);
    set_map_info(info_map, map);
    while (1) {
        end = end_game(info_map, case_info);
        if (end == 2)
            return (1);
        if (end == 1)
            return (0);
        my_print_tab_window(terminal, info_map);
        noecho();
        ch = getch();
        (ch == KEY_DOWN) ? exec_move_down(terminal, info_map, case_info) : 1;
        (ch == KEY_UP) ? exec_move_up(terminal, info_map, case_info) : 1;
        (ch == KEY_RIGHT) ? exec_move_right(terminal, info_map, case_info) : 1;
        (ch == KEY_LEFT) ? exec_move_left(terminal, info_map, case_info) : 1;
        (ch == 32) ? reset_map(info_map, terminal) : 1;
    }
    return (0);
}
