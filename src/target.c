#include "display.h"
#include <bullet.h>
#include <invaders.h>
#include <stdio.h>
#include <stdlib.h>
#include <target.h>

TargetSt *target = NULL;
int count_target = 0;
int capacity_target = 0;

void set_target(DisplayGame game, Image img) {
  XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
            img.image, 0, 0, img.x, img.y, img.width, img.height);
}

void create_target(DisplayGame game, int bullet_ind) {
  printf("%d\n", count_invaders);
  for (int j = 0; j < count_invaders; j++) {
    if (invaders[j].image.x <= bullet[bullet_ind].x &&
        invaders[j].image.x + invaders[j].image.width >= bullet[bullet_ind].x) {

      if (count_target == capacity_target) {
        int new_capacity = capacity_target == 0 ? 2 : capacity_target * 2;

        TargetSt *new_target = target == NULL
                                 ? calloc(new_capacity, sizeof(TargetSt))
                                 : realloc(target, new_capacity * sizeof(TargetSt));
        if (!new_target) {
          perror("Failed to allocate memory for targets");
          exit(EXIT_FAILURE);
        }
        target = new_target;
        capacity_target = new_capacity;
      }

      target[count_target].image = game.media.images.target;
      target[count_target].image.x =
          invaders[j].image.x - invaders[j].image.width / 4;
      target[count_target].image.y =
          invaders[j].image.y - invaders[j].image.height / 2;
      target[count_target].bullet = bullet_ind;
      target[count_target].invaders = &invaders[j];
      count_target++;
    }
  }
}

void run_target(DisplayGame *game) {
  for (int i = 0; i < count_target; i++) {
    target[i].image.y = target[i].invaders->image.height -
                        target[i].invaders->image.height / 2;
    set_bullet(*game, target[i].image);
    printf("%d\n",target[2].image.y);
  }

  // int write_index = 0;
  // for (int read_index = 0; read_index < count_target; read_index++) {
  //   if (target[read_index].image.y < game->height) {
  //     if (write_index != read_index) {
  //       target[write_index] = target[read_index];
  //     }
  //     write_index++;
  //   }
  // }
  // count_target = write_index;
}

