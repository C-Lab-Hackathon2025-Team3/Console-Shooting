#pragma once
#ifndef PLAYER_H
#define PLAYER_H


typedef struct {
    int x;
    int y;
    int radius;
} Player;

void draw_player(int centerX, int centerY, int radius);

#endif // PLAYER_H