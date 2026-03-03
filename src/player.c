#include "player.h"

#include <stdlib.h>
#include "animationPlayer.h"
#include "assetManager.h"
#include "world.h"

#define TILESIZE 16

void initAnimations();

Animation anim_walkUp;
Animation anim_walkDown;
Animation anim_walkLeft;
Animation anim_walkRight;

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
    Vector2 currTile;
} Player;

void handleInput(Player *p);
void interact(Player *p);

double lastUpdateTime = 0.0;

Player *createPlayer(Vector2 pos)
{
    Player *p = malloc(sizeof(Player));
    p->pos = pos;
    p->dir = UP;
    p->currTile = getTileFromPos(pos);
    initAnimations();
    return p;
}

void destroyPlayer(Player *p)
{
    if (p == NULL) return;
    free(p);
}

void initAnimations()
{
    Rectangle walkAnimRects[3] = { (Rectangle) {0, 0, 16, 32}, (Rectangle) {17, 0, 16, 32}, (Rectangle) {34, 0, 16, 32} };
    anim_walkUp = createAnimation(WALK_UP, 3, (int)UP, walkAnimRects, 3);
    anim_walkDown = createAnimation(WALK_DOWN, 3, (int)DOWN, walkAnimRects, 3);
    anim_walkLeft = createAnimation(WALK_LEFT, 3, (int)LEFT, walkAnimRects, 3);
    anim_walkRight = createAnimation(WALK_RIGHT, 2, (int)RIGHT, walkAnimRects, 3);
}

void updatePlayer(Player *p)
{
    handleInput(p);
}

void drawPlayer(const Player *p)
{
    //DrawRectangle(p->pos.x, p->pos.y, 40, 40, BLACK);
    Rectangle destRect = { p->pos.x, p->pos.y, 32, 64};
    Vector2 origin = {0, 0};
    switch (p->dir)
    {
    case LEFT:
        drawAnimation(anim_walkLeft, destRect, origin, 0, WHITE);
        break;
    case RIGHT:
        drawAnimation(anim_walkRight, destRect, origin, 0, WHITE);
        break;
    case UP:
        drawAnimation(anim_walkUp, destRect, origin, 0, WHITE);
        break;
    case DOWN:
        drawAnimation(anim_walkDown, destRect, origin, 0, WHITE);
        break;
    }
}

void handleInput(Player *p)
{
    
}

void interact(Player *p)
{

}