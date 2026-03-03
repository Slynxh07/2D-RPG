#ifndef WORLD_H
#define WORLD_H

#include "raylib.h"
#include "player.h"

#define CELL_SIZE 32

typedef struct Tileset Tileset;

typedef struct Map
{
    int width, height;
    int *tiles;
    Tileset *ts;
    /*
    Npcs
    Tileset
    CollisionData
    */
} Map;

Map *createMap(int width, int height);
void destroyMap(Map *m);
void setCurrentMap(Map *m);

int tileAheadWalkable(Player *p);
Vector2 getTileFromPos(Vector2 pos);
int getTile(int x, int y);
void setTile(int x, int y, int val);

void drawMap();

#endif