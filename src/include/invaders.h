#ifndef INVADERS_H
#define INVADERS_H

#include "display.h"

void set_inv(DisplayGame game, Image inv);

void run_inv (DisplayGame *game);

void* create_random(void* arg) ;

typedef enum {
L1 ,
M1,
S1
}TypeInvaders;

typedef struct {
	  Image image;
	  int health;
	TypeInvaders type ;
} InvadersSt;


extern InvadersSt *invaders;
extern int count_invaders;
extern int capcity_invaders;
#endif
