#ifndef BULLET_H
#define BULLET_H

#include "display.h"
void set_bullet(DisplayGame game, Image inv);

void run_bullet (DisplayGame *game);

void shut(DisplayGame game) ;

extern Image *bullet;
extern int count_bullet;
extern int capcity_bullet;

#endif
