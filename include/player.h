#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player Player;

Player *createPlayer();
void destroyPlayer(Player *p);

void updatePlayer(Player *p);
void drawPlayer(const Player *p);

#endif