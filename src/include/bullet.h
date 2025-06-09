#ifndef BULLET_H
#define BULLET_H

#include "display.h"
typedef struct {
	  Image bullet;
} BulletSt;
void set_bullet(DisplayGame game, Image inv);

void run_bullet (DisplayGame *game);

void shut(DisplayGame game, int x, int y) ;

extern BulletSt *bullet;
extern int count_bullet;
extern int capcity_bullet;

#endif
