/*
** EPITECH PROJECT, 2018
** error
** File description:
** error and help
*/

#include "../include/my_sokoban.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void put_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     ");
    my_putstr("map file representing the warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("         ");
    my_putstr("‘P’ for the player, ‘X’ for boxes ");
    my_putstr("and ‘O’ for storage locations.\n");
}

int error_gestion(int ac, char **av)
{
    struct stat byte;

    int fd = 0;

    if (ac != 2) {
        my_putstr("bad arg\n");
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        put_help();
        return (0);
    }
    if ((fd = open(av[1], O_RDONLY)) == -1) {
        my_putstr("no file to open\n");
        return (84);
    }
    stat(av[1], &byte);
    if (byte.st_size == 0) {
        my_putstr("bad file\n");
        return (84);
    }
    return (fd);
}

void my_free_tab(char **tab)
{
    int it = 0;

    while (it < line_size_tab(tab)) {
        free(tab[it]);
        it++;
    }
    free(tab);
}

int cheak_map(char **map)
{
    int y = 0;
    int x = 0;

    while (map[y]) {
        while (map[y][x]) {
            if (map[y][x] != '#' && map[y][x] != 'X' &&
             map[y][x] != 'P' && map[y][x] != ' ' && map[y][x] != 'O')
                return (1);
            x++;
        }
        y++;
        x = 0;
    }
    return (0);
}