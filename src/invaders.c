#include "bullet.h"
#include "display.h"
#include <invaders.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

InvadersSt *invaders = {0};
int count_invaders = 0;
int capcity_invaders = 0;

void set_inv(DisplayGame game, Image inv) {
  XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
            inv.image, 0, 0, inv.x, inv.y, inv.width, inv.height);
};

pthread_mutex_t invader_mutex = PTHREAD_MUTEX_INITIALIZER;

void *create_random(void *arg) {

  srand(time(NULL));

  DisplayGame *game = (DisplayGame *)arg;
  while (1) {
    sleep(6 - game->hard_level);
    pthread_mutex_lock(&invader_mutex);

    if (count_invaders == capcity_invaders) {
      capcity_invaders = capcity_invaders + 1;

      invaders =
          invaders == NULL
              ? calloc(capcity_invaders, sizeof(InvadersSt))
              : realloc(invaders, (capcity_invaders) * sizeof(InvadersSt));
    }
    srand(time(NULL));

    int num = rand() % (10 * (game->hard_level + 1));

    if (num < 20) {
      TypeInvaders type = L1;
      invaders[count_invaders].image = game->media.images.invaders_l1;
      invaders[count_invaders].health = 3;
      invaders[count_invaders].type = L1;
    }
    if (num >= 20 && num < 50) {
      TypeInvaders type = M1;
      invaders[count_invaders].image = game->media.images.invaders_m1;
      invaders[count_invaders].health = 6;
      invaders[count_invaders].type = M1;
    }
    if (num >= 50) {
      TypeInvaders type = S1;
      invaders[count_invaders].image = game->media.images.invaders_s1;
      invaders[count_invaders].health = 12;
      invaders[count_invaders].type = S1;
    }

    invaders[count_invaders].image.y = -10;
    invaders[count_invaders].image.x =
        (rand() % (game->width - invaders[count_invaders].image.width)) + 1;
    count_invaders += 1;

    pthread_mutex_unlock(&invader_mutex);
  }
}

void run_inv(DisplayGame *game) {
  game->hard_level = game->time_pass < 110 ? game->time_pass / 10 : 6;
  for (int i = 0; i < count_invaders; i++) {
    invaders[i].image.y += 1;
    set_inv(*game, invaders[i].image);

    if (invaders[i].image.y >= game->height ) {
      game->health--;
      for (int j = 0; j < capcity_invaders - 2; j++) {
        invaders[j] = invaders[j + 1];
      }
    }
  }
};
