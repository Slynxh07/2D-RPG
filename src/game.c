#include "game.h"
#include "raylib.h"
#include "assetManager.h"
#include "world.h"
#include "player.h"

#define HEIGHT 600
#define WIDTH 900

void drawGame();
void updateGame();

Player *player;

void initGame()
{
    InitWindow(WIDTH, HEIGHT, "notPokemon");
    SetTargetFPS(60);
    loadAssets();
    Map *m = createMap(WIDTH / 32, HEIGHT / 32);
    setCurrentMap(m);
    player = createPlayer((Vector2) { 900/2, 600/2});
}

void runGame()
{
    while (!WindowShouldClose())
    {
        updateGame();
        drawGame();
    }
}

void closeGame()
{
    unloadAssets();
}

void drawGame()
{
    BeginDrawing();

    ClearBackground(LIGHTGRAY);

    DrawFPS(10, 10);

    drawMap();
    drawPlayer(player);

    EndDrawing();
}

void updateGame()
{
    updatePlayer(player);
}