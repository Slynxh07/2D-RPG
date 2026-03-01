#include "animationPlayer.h"
#include <stdlib.h>
#include <string.h>

Animation createAnimation(Texture2D texture, int fps, int id, Rectangle rectangles[], int numFrames)
{
    Animation animation =
    {
        .fps = fps,
        .id = id,
        .numFrames = numFrames,
        .texture = texture,
        .rects = NULL
    };

    animation.rects = malloc(sizeof(Rectangle) * numFrames);
    if (animation.rects == NULL)
    {
        TraceLog(LOG_ERROR, "malloc failed");
        animation.numFrames = 0;
        return animation;
    }
    memcpy(animation.rects, rectangles, sizeof(Rectangle) * numFrames);
    return animation;
}

void destroyAnimation(Animation animation)
{
    free(animation.rects);
}

void drawAnimation(Animation animation, Rectangle dest, Vector2 origin, float rotation, Color tint)
{
    int i = (int)(GetTime() * animation.fps) % animation.numFrames;

    Rectangle src = animation.rects[i];
    DrawTexturePro(animation.texture, src, dest, origin, rotation, tint);
}