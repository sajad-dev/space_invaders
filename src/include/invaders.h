#ifndef INVADERS_H
#define INVADERS_H

#include "display.h"

void set_inv(DisplayGame game, Image inv);

void run_inv (DisplayGame *game);


void* create_random(void* arg) ;
typedef struct {
	  Image image;
	  int health;
} InvadersSt;


extern InvadersSt *invaders;
extern int count_invaders;
extern int capcity_invaders;
#endif
