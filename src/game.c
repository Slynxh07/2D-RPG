#include "game.h"
#include "player.h"
#include "raylib.h"

#define HEIGHT 600
#define WIDTH 900

void drawGame();
void updateGame();

Player *player;

void initGame()
{
    InitWindow(WIDTH, HEIGHT, "notPokemon");
    SetTargetFPS(60);
    player = createPlayer();
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

}

void drawGame()
{
    BeginDrawing();

    ClearBackground(LIGHTGRAY);

    DrawFPS(10, 10);

    drawPlayer(player);

    EndDrawing();
}

void updateGame()
{
    updatePlayer(player);
}