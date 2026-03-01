#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include "raylib.h"

extern Texture2D WALK_DOWN;
extern Texture2D WALK_UP;
extern Texture2D WALK_RIGHT;
extern Texture2D WALK_LEFT;

void loadAssets();
void unloadAssets();

#endif