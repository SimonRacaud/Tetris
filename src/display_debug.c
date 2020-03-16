/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** tetris
*/

#include "game_t.h"
#include "debug.h"
#include "my.h"

static int key_manage(char *str, char *key)
{
    if (key && key[0] == '\e') {
        printw("%s : ^E%s\n", str, key + 1);
    } else if (key && key[0] == ' ') {
        printw("%s : (space)\n", str);
    } else
        printw("%s : %s\n", str, key);
    return EXIT_SUCCESS;
}

static int key_display(config_t *config)
{
    char *name[] = {"Key Left", "Key Right", "Key Turn", "Key Drop",
    "Key Quit", "Key Pause"};

    if (key_manage(name[0], config->key[LEFT_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[1], config->key[RIGHT_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[2], config->key[TURN_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[3], config->key[DROP_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[4], config->key[QUIT_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    if (key_manage(name[5], config->key[PAUSE_KEY]) == EXIT_ERROR)
        return EXIT_ERROR;
    return EXIT_SUCCESS;
}

static void display_tetriminos_content(tetrimino_t *piece)
{
    printw("Tetriminos : Name %s : Size %i*%i : Color %i : \n",
    piece->name, piece->width, piece->height, piece->color);
    for (int u = 0; u < piece->height; u++)
        printw("%s\n", piece->mtx[u]);
}

static void display_tetriminos(game_t *tetris)
{
    printw("Tetriminos : %i\n", tetris->pieces.size);
    for (int i = 0; i < tetris->pieces.size; i++) {
        if (!tetris->pieces.pc[i].mtx)
            printw("Tetriminos : Name %s : Error\n", PIECE(i).name);
        else {
            display_tetriminos_content(&tetris->pieces.pc[i]);
        }
    }
}

int show_debug_screen(game_t *tetris)
{
    config_t *config = &tetris->conf;

    initscr();
    printw("*** DEBUG MODE ***\n");
    if (key_display(config) == EXIT_ERROR)
        return EXIT_ERROR;
    if (config->hide_next_tetrimino)
        printw("Next : Yes\n");
    else
        printw("Next : No\n");
    printw("Level : %i\n", config->start_level);
    printw("Size : %i*%i\n", config->map_width, config->map_height);
    display_tetriminos(tetris);
    printw("Press any key to start Tetris\n");
    refresh();
    getch();
    endwin();
    return EXIT_SUCCESS;
}
