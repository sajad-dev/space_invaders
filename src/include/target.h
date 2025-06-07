#ifndef TARGET_H
#define TARGET_H

#include "display.h"
#include "invaders.h"
typedef struct {
  Image image;
  int bullet;
  InvadersSt *invaders;
} TargetSt;


extern TargetSt *target ;
void create_target (DisplayGame game,int bullet_ind);

void run_target(DisplayGame *game);

#endif


