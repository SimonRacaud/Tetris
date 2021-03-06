/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Created: 2020-03-09T08:24:41+01:00 | Author: simon
*/

#ifndef PIECES_H
#define PIECES_H

#include <stdbool.h>

typedef struct coord {
    int x;
    int y;
} coord_t;

typedef struct tetrmimino {
    char *name;
    char **mtx;
    int height;
    int width;
    int color;
} tetrimino_t;

typedef struct pieces {
    tetrimino_t *pc;
    int size;
} pieces_t;

typedef struct player_piece {
    tetrimino_t *piece;
    coord_t coord;
    int speed_y;
    bool is_fall;
} player_piece_t;

#endif
