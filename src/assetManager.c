#include "assetManager.h"

Texture2D WALK_DOWN;
Texture2D WALK_UP;
Texture2D WALK_RIGHT;
Texture2D WALK_LEFT;

void loadAssets()
{
    WALK_DOWN = LoadTexture("Assets/player_sprites/walk_down.png");
    WALK_UP = LoadTexture("Assets/player_sprites/walk_up.png");
    WALK_RIGHT = LoadTexture("Assets/player_sprites/walk_right.png");
    WALK_LEFT = LoadTexture("Assets/player_sprites/walk_left.png");
}

void unloadAssets()
{
    UnloadTexture(WALK_DOWN);
    UnloadTexture(WALK_UP);
    UnloadTexture(WALK_RIGHT);
    UnloadTexture(WALK_LEFT);
}