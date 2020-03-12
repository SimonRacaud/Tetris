/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T13:58:20+01:00 | Author: simon
*/

#include "tetris.h"

int tetris(int argc, char **argv, char **env)
{
    game_t tetris;

    if (game_init(&tetris, argv, argc, env) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (tetris.conf.debug_mode)
        show_debug_screen(&tetris);
    game_destroy(&tetris);
    return EXIT_SUCCESS;
}