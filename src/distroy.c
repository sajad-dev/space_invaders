#include "bullet.h"
#include "display.h"
#include "invaders.h"
#include <X11/Xlib.h>
#include <distroy.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>



Distroy *distroy_list;
int count_distroy_list;
int capcity_distroy_list;

void distroy_invaders(DisplayGame game) {
  for (int i = 0; i < count_distroy_list; i++) {
    XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
              game.media.images.distroy_invaders.image, 0, 0, distroy_list[i].x,
              distroy_list[i].y, game.media.images.distroy_invaders.width,
              game.media.images.distroy_invaders.height);
    distroy_list[i].time_ds--;
    if (distroy_list[i].time_ds < 0) {
      for (int k = i; k < capcity_distroy_list - 1; k++) {
        distroy_list[k] = distroy_list[k + 1];
      }
      count_distroy_list--;
    }
  }
}

void add_distroy(Distroy dis) {
  if (count_distroy_list == capcity_distroy_list) {
    capcity_distroy_list = capcity_distroy_list + 1;

    distroy_list =
        distroy_list == NULL
            ? calloc(capcity_distroy_list, sizeof(Distroy))
            : realloc(distroy_list, (capcity_distroy_list) * sizeof(Distroy));
  }
  distroy_list[count_distroy_list] = dis;
  count_distroy_list ++;
}

void deailing(DisplayGame game) {
  for (int i = 0; i < count_bullet; i++) {
    for (int j = 0; j < count_invaders; j++) {
      if (bullet[i].x >= invaders[j].image.x &&
          bullet[i].x <= invaders[j].image.x + invaders[j].image.width &&
          invaders[j].image.y <= bullet[i].y &&
          invaders[j].image.y + invaders[j].image.height >= bullet[i].y) {

        for (int k = i; k < capcity_bullet - 1; k++) {
          bullet[k] = bullet[k + 1];
        }
        count_bullet--;

        invaders[j].health--;
        if (invaders[j].health <= 0) {
          Distroy args;
          args.x = invaders[j].image.x;
          args.y = invaders[j].image.y;
          args.time_ds = 6;
	  add_distroy(args);

          for (int k = j; k < capcity_invaders - 1; k++) {
            invaders[k] = invaders[k + 1];
          }
          count_invaders--;
        }

        break;
      }
    }
  }
}
