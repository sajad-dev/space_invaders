#include "display.h"
#include <invaders.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
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
    sleep(2);
    pthread_mutex_lock(&invader_mutex);

    if (count_invaders == capcity_invaders) {
      capcity_invaders = capcity_invaders + 1;

      invaders = invaders == NULL
                     ? calloc(capcity_invaders, sizeof(Image))
                     : realloc(invaders, (capcity_invaders) * sizeof(Image));
    }

    int num = 1;

    switch (num) {
    case 1:
      invaders[count_invaders].image = game->media.images.invaders_l1;
    }

    invaders[count_invaders].image.y = -10;
    invaders[count_invaders].image.x =
        (rand() % (game->width - invaders[count_invaders].image.width + 50)) +
        1;
    count_invaders += 1;

    pthread_mutex_unlock(&invader_mutex);
  }
}

void run_inv(DisplayGame *game) {

  for (int i = 0; i < count_invaders; i++) {
    invaders[i].image.y += 1;
    set_inv(*game, invaders[i].image);
    if (invaders[i].image.y >= game->height+20) {
      for (int j = 0; j < capcity_invaders - 2; j++) {
        invaders[j] = invaders[j + 1];
      }
    }
  }
};
