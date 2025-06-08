#include "target.h"
#include <bullet.h>
#include <stdio.h>
#include <stdlib.h>

Image *bullet = NULL;
int count_bullet = 0;
int capcity_bullet = 0;

void set_bullet(DisplayGame game, Image bullet_img) {
  XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
            bullet_img.image, 0, 0, bullet_img.x, bullet_img.y,
            bullet_img.width, bullet_img.height);
};

void shut(DisplayGame game) {
  if (count_bullet == capcity_bullet) {
    capcity_bullet = capcity_bullet + 1;

    bullet = bullet == NULL ? calloc(capcity_bullet, sizeof(Image))
                            : realloc(bullet, (capcity_bullet) * sizeof(Image));
  }
  bullet[count_bullet] = game.media.images.bullet;
  bullet[count_bullet].x =
      game.media.images.ship.x + (game.media.images.ship.width / 2);
  bullet[count_bullet].y = game.media.images.ship.y;

  // create_target(game, count_bullet);

  count_bullet += 1;
}

void run_bullet(DisplayGame *game) {
  for (int i = 0; i < count_bullet;) {
    bullet[i].y -= 10;
    if (bullet[i].y < 0) {
      for (int j = i; j < count_bullet - 1; j++) {
        bullet[j] = bullet[j + 1];
      }
      count_bullet--;
      continue;
    } else {
      set_bullet(*game, bullet[i]);
      i++;
    }
  }
}
