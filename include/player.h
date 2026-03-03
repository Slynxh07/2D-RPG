#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

typedef struct Player Player;

Player *createPlayer(Vector2 pos);
void destroyPlayer(Player *p);

void updatePlayer(Player *p);
void drawPlayer(const Player *p);

#endif