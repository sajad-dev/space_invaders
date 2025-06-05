#ifndef INVADERS_H
#define INVADERS_H

#include "display.h"

void set_inv(DisplayGame game, Image inv);

void run_inv (DisplayGame *game);

void* create_random(void* arg) ;

#endif
