#ifndef ANIMATION_PLAYER_H
#define ANIMATION_PLAYER_H

#include "raylib.h"

typedef struct Animation
{
    Texture2D texture;
    int fps;
    int id;
    int numFrames;
    Rectangle *rects;
} Animation;

Animation createAnimation(Texture2D texture, int fps, int id, Rectangle rectangles[], int numFrames);
void destroyAnimation(Animation animation);
void drawAnimation(Animation animation, Rectangle dest, Vector2 origin, float rotation, Color tint);

#endif