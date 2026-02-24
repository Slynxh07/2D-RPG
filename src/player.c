#include <stdlib.h>
#include "player.h"
#include "raylib.h"

#define SPEED 10

typedef struct Player
{
    Vector2 pos;
    Vector2 velocity;
} Player;

void handleInput(Player *p);

Player *createPlayer()
{
    Player *p = malloc(sizeof(Player));
    p->pos = (Vector2) { 900/2, 600/2};
    p->velocity = (Vector2) {0, 0};
    return p;
}

void destroyPlayer(Player *p)
{
    if (p == NULL) return;
    free(p);
}

void updatePlayer(Player *p)
{
    handleInput(p);

    p->pos.x += p->velocity.x;
    p->pos.y += p->velocity.y;
}

void drawPlayer(const Player *p)
{
    DrawRectangle(p->pos.x, p->pos.y, 10, 10, BLACK);
}

void handleInput(Player *p)
{
    int xDir = (IsKeyDown(KEY_D) ? 1 : 0) - (IsKeyDown(KEY_A) ? 1 : 0);
    int yDir = (IsKeyDown(KEY_S) ? 1 : 0) - (IsKeyDown(KEY_W) ? 1 : 0);

    if (xDir && yDir) p->velocity = (Vector2) {0, 0};
    else if (xDir) p->velocity.x = xDir * SPEED;
    else if (yDir) p->velocity.y = yDir * SPEED;
    else p->velocity = (Vector2) {0, 0};
}