#include "target.h"
#include <bullet.h>
#include <stdio.h>
#include <stdlib.h>

BulletSt *bullet = NULL;
int count_bullet = 0;
int capcity_bullet = 0;

void set_bullet(DisplayGame game, Image bullet_img) {
  XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
            bullet_img.image, 0, 0, bullet_img.x, bullet_img.y,
            bullet_img.width, bullet_img.height);
};

void shut(DisplayGame game, int x, int y) {
  if (count_bullet == capcity_bullet) {
    capcity_bullet = capcity_bullet + 1;

    bullet = bullet == NULL
                 ? calloc(capcity_bullet, sizeof(BulletSt))
                 : realloc(bullet, (capcity_bullet) * sizeof(BulletSt));
  }
  bullet[count_bullet].bullet = game.media.images.bullet;
  bullet[count_bullet].bullet.x = x;
  bullet[count_bullet].bullet.y = y;

  // create_target(game, count_bullet);

  count_bullet += 1;
}

void run_bullet(DisplayGame *game) {
  for (int i = 0; i < count_bullet;) {
    bullet[i].bullet.y -= 10;
    if (bullet[i].bullet.y < 0) {
      for (int j = i; j < count_bullet - 1; j++) {
        bullet[j] = bullet[j + 1];
      }
      count_bullet--;
      continue;
    } else {
      set_bullet(*game, bullet[i].bullet);
      i++;
    }
  }
}
