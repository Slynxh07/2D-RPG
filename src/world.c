#include "world.h"
#include <stdlib.h>

Map *currentMap;

typedef struct Tileset
{
    Color grass;
    Color water;
} Tileset;

Tileset *createTileset()
{
    Tileset *ts = malloc(sizeof(Tileset));
    ts->grass = (Color) {0x3F, 0x9B, 0x0b, 0xFF};
    ts->water = (Color) {0x0E, 0x87, 0xCC, 0xFF};
    return ts;
}

void destroyTileset(Tileset *ts)
{
    free(ts);
}

Map *createMap(int width, int height)
{
    Map *m = malloc(sizeof(Map));
    m->width = width;
    m->height = height;
    m->tiles = calloc(width * height, sizeof(int));
    m->ts = createTileset();
    return m;
}

void setCurrentMap(Map *m)
{
    currentMap = m;
}

void destroyMap(Map *m)
{
    free(m->tiles);
    destroyTileset(m->ts);
    free(m);
}

Vector2 getTileFromPos(Vector2 pos)
{
    Vector2 tile;
    tile.x = (int)(pos.x / CELL_SIZE);
    tile.y = (int)(pos.y / CELL_SIZE);

    if (tile.x < 0) tile.x = 0;
    if (tile.y < 0) tile.y = 0;
    if (tile.x >= currentMap->width) tile.x = currentMap->width - 1;
    if (tile.y >= currentMap->height) tile.y = currentMap->height - 1;
    return tile;
}

int getTile(int x, int y)
{
    return currentMap->tiles[y * currentMap->width + x];
}

void setTile(int x, int y, int val)
{
    currentMap->tiles[y * currentMap->width + x] = val;
}

void drawMap()
{
    for (int i = 0; i < currentMap->height; i++)
        for (int j = 0; j < currentMap->width; j++)
        {
            Color c = i % 2 == 0 ? (j % 2 == 0 ? currentMap->ts->grass : currentMap->ts->water) : (j % 2 != 0 ? currentMap->ts->grass : currentMap->ts->water);
            DrawRectangle(CELL_SIZE * j, CELL_SIZE * i, CELL_SIZE, CELL_SIZE, c);
        }
}