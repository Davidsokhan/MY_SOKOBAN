/*
** EPITECH PROJECT, 2018
** my_sokoban.h
** File description:
** my sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

typedef struct s_terminal_size
{
    int x;
    int y;
    int save_x;
    int save_y;
} t_terminal_size;

typedef struct s_map_info
{
    int line_size;
    int column_size;
    int nbr_case;
    int x;
    int y;
    int x_origin;
    int y_origin;
    char **map;
    char **map_origin;
} t_map_info;

typedef struct s_free_case
{
    int x;
    int y;
} t_free_case;

typedef struct s_info_box
{
    int x;
    int y;
} t_info_box;

void my_putchar(char c);
void my_putstr(char *str);
void my_show_tab(char **tab);
int end_game(t_map_info *info_map, t_free_case *case_info);
void put_help(void);
int error_gestion(int ac, char **av);
int cheak_map(char **map);
int column_size(char *str);
int line_size(char *str);
int line_size_tab(char **tab);
int column_size_tab(char **tab);
char **put_on_tab(char *str);
char **file_on_tab(int fd, char *pathname);
int count_box(char **map);
void my_print_tab_window(t_terminal_size *terminal, t_map_info *info_map);
void exec_move_down(t_terminal_size *terminal, t_map_info *info_map, t_free_case *case_info);
void exec_move_up(t_terminal_size *terminal, t_map_info *info_map, t_free_case *case_info);
void exec_move_right(t_terminal_size *terminal, t_map_info *info_map, t_free_case *case_info);
void exec_move_left(t_terminal_size *terminal, t_map_info *info_map, t_free_case *case_info);
void replace_case_free(t_map_info *info_map, t_free_case *case_info);
void my_free_tab(char **tab);
void reset_map(t_map_info *info_map, t_terminal_size *terminal);
int move_down(t_map_info *info_map, t_free_case *case_info);
int move_up(t_map_info *info_map, t_free_case *case_info);
int move_right(t_map_info *info_map, t_free_case *case_info);
int move_left(t_map_info *info_map, t_free_case *case_info);
int count_free_case(char **map);
t_free_case *set_free_case_info(char **map);
t_info_box *set_struct_box(char **map);
void set_terminal_info(t_terminal_size *terminal, char **map);
void print_tab(char **map, int line_size, t_terminal_size *terminal);
char **my_tabcpy(char **map);
int my_sokoban(char **map);
int loose_case(t_map_info *info_map, char **map, int x, t_free_case *case_info);
int you_loose(t_map_info *info_map, t_free_case *case_info);
void set_map_info(t_map_info *info_map, char **map);

#endif
