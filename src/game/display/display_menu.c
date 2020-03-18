/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-11T17:53:44+01:00 | Author: simon
*/

#include "tetris.h"

static void display_time(game_t *tetris, window_t *menu)
{
    int time = (clock() / CLOCKS_PER_SEC) - tetris->time_sub;
    int minutes = (time / 60);
    int seconds = time - (minutes * 60);

    mvwprintw(menu->w, 11, 2, "Time: %.2d:%.2d", minutes, seconds);
}

static void display_next_piece(game_t *tetris, window_t *menu)
{
    int pos_x = (menu->width / 2) - (tetris->next_piece->width / 2);

    mvwprintw(menu->w, 13, 2, "Next piece:");
    color_init();
    for (int i = 0; i < tetris->next_piece->height; i++) {
        wattron(menu->w, COLOR_PAIR(tetris->next_piece->color));
        mvwprintw(menu->w, 15 + i, pos_x, "%s",
            tetris->next_piece->mtx[i]);
        wattroff(menu->w, COLOR_PAIR(tetris->next_piece->color));
    }
}

int display_menu(game_t *tetris)
{
    window_t *menu = &tetris->menu;
    int title_posx = (menu->width / 2) - 5;

    box(menu->w, ACS_VLINE, ACS_HLINE);
    mvwprintw(menu->w, 1, title_posx, "-- MENU --");
    mvwprintw(menu->w, 3, 2, "Score: %d", tetris->score);
    mvwprintw(menu->w, 5, 2, "High Score: %d", tetris->high_score);
    mvwprintw(menu->w, 7, 2, "Level: %d", tetris->level);
    mvwprintw(menu->w, 9, 2, "Lines: %d", tetris->line);
    display_time(tetris, menu);
    if (tetris->conf.hide_next_tetrimino == false)
        display_next_piece(tetris, menu);
    return EXIT_SUCCESS;
}
