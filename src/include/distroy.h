#ifndef DISTROY_H
#define	DISTROY_H

#include "display.h"
typedef struct Distroy {
	int x;
	int y;
	int time_ds;
} Distroy;
void deailing (DisplayGame *game);
void distroy_invaders(DisplayGame game) ;
extern Distroy *distroy_list;

#endif

