/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my_sokoban.h"

char **put_on_tab(char *str)
{
    int it = 0;
    int line = 0;
    int column = 0;
    char **tab = malloc(sizeof(char *) * (line_size(str) + 1));

    while (line < line_size(str)) {
        column = 0;
        tab[line] = malloc(sizeof(char) * (column_size(str) + 1));
        while (str[it] != '\n') {
            tab[line][column] = str[it];
            it++;
            column++;
        }
        it++;
        tab[line][column] = '\0';
        line++;
    }
    tab[line] = NULL;
    return (tab);
}

char **file_on_tab(int fd, char *pathname)
{
    struct stat byte;
    char *str_tab;
    char **tab;
    
    stat(pathname, &byte);
    str_tab = malloc(sizeof(char) * (byte.st_size + 1));
    read(fd, str_tab, byte.st_size);
    str_tab[byte.st_size] = '\0';
    tab = put_on_tab(str_tab);
    free(str_tab);
    return (tab);
}

int main(int ac, char **av)
{
    int fd = error_gestion(ac, av);
    char **map;
    int res = 0;

    if (fd == 84)
        return (84);
    if (fd == 0) {
        return (0);
    }
    (av[1][0] == '-' && av[1][0] == 'h') ? put_help() : 1;
    map = file_on_tab(fd, av[1]);
    if (cheak_map(map) == 1) {
        my_putstr("bad map!\n");
        return (84);
    }
    res = my_sokoban(map);
    return (res);
}
