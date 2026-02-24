#include <stdlib.h>
#include "player.h"
#include "raylib.h"

#define TILESIZE 40

typedef enum Direction 
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct Player
{
    Vector2 pos;
    Direction dir;
    int sprinting;
} Player;

void handleInput(Player *p);
void move(Player *p, int numTiles);
void interact(Player *p);
int canWalk(double interval);

double lastUpdateTime = 0.0;

Player *createPlayer()
{
    Player *p = malloc(sizeof(Player));
    p->pos = (Vector2) { 900/2, 600/2};
    p->dir = UP;
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
}

void drawPlayer(const Player *p)
{
    DrawRectangle(p->pos.x, p->pos.y, 40, 40, BLACK);
}

void handleInput(Player *p)
{
    Direction prevDir = p->dir;

    int numTiles = 0;
    if (IsKeyDown(KEY_A))
    {
        p->dir = LEFT;
        numTiles = 1;
    }
    else if (IsKeyDown(KEY_D))
    {
        p->dir = RIGHT;
        numTiles = 1;
    }
    else if (IsKeyDown(KEY_W))
    {
        p->dir = UP;
        numTiles = 1;
    }
    else if (IsKeyDown(KEY_S))
    {
        p->dir = DOWN;
        numTiles = 1;
    }

    p->sprinting = IsKeyDown(KEY_LEFT_SHIFT);

    if (prevDir != p->dir) numTiles = 0;

    if (p->sprinting && numTiles) numTiles = 2;

    if (canWalk(0.1)) move(p, numTiles);
}

void interact(Player *p)
{

}

void move(Player *p, int numTiles)
{
    switch (p->dir)
    {
    case LEFT:
        p->pos.x -= TILESIZE * numTiles;
        break;
    case RIGHT:
        p->pos.x += TILESIZE * numTiles;
        break;
    case UP:
        p->pos.y -= TILESIZE * numTiles;
        break;
    case DOWN:
        p->pos.y += TILESIZE * numTiles;
        break;
    }
}

int canWalk(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return 1;
	}
	return 0;
}