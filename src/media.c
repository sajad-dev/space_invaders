#include "display.h"
#include <media.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image load_image(DisplayGame game, const char *path, int x, int y) {
  Image img;
  unsigned char *data =
      stbi_load(path, &img.width, &img.height, &img.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image: %s\n", path);
  }

  img.image =
      XCreateImage(game.display, DefaultVisual(game.display, game.screen), 24,
                   ZPixmap, 0, (char *)data, img.width, img.height, 32, 0);

  img.x = x;
  img.y = y;

  return img;
}

void ship(DisplayGame game, Images *images) {
  images->ship = load_image(game,
                            "/home/sajad/Documents/Programming/space_invaders/"
                            "Assets/Sprites/player2.png",
                            game.width / 2 - 50, game.height - 50);
}

void add_distroy_invaders(DisplayGame game, Images *images) {
  images->distroy_invaders =
      load_image(game,
                 "/home/sajad/Documents/Programming/space_invaders/Assets/"
                 "Sprites/Explosions/invaderExplosion.png",
                 game.width / 2 - 50, game.height );
}

void bullet_add(DisplayGame game, Images *images) {
  images->bullet =
      load_image(game,
                 "/home/sajad/Documents/Programming/space_invaders/Assets/"
                 "Sprites/Projectiles/Projectile_Player.png",
                 0, 0);
}
void target_add(DisplayGame game, Images *images) {
  images->target = load_image(game,
                              "/home/sajad/Documents/Programming/"
                              "space_invaders/Assets/Sprites/targetMark.png",
                              0, 0);
}

void invader(DisplayGame game, Images *images) {
  images->invaders_l1 =
      load_image(game,
                 "/home/sajad/Documents/Programming/space_invaders/Assets/"
                 "Sprites/Invaders/invaderL1.png",
                 0, 0);

  //   data = stbi_load("../Assets/Sprites/Invaders/invaderL2.png",
  //   &invader.width,
  //                    &invader.height, &invader.channels, 4);

  //   if (!data) {
  //     fprintf(stderr, "Failed to load image\n");
  //   }

  //   invader.image = XCreateImage(
  //       game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap,
  //       0, (char *)data, invader.width, invader.height, 32, 0);

  //   invader.x = 0;
  //   invader.y = 0;
  //   images->invaders_l2 = invader;

  //   data = stbi_load("../Assets/Sprites/Invaders/invaderM1.png",
  //   &invader.width,
  //                    &invader.height, &invader.channels, 4);

  //   if (!data) {
  //     fprintf(stderr, "Failed to load image\n");
  //   }

  //   invader.image = XCreateImage(
  //       game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap,
  //       0, (char *)data, invader.width, invader.height, 32, 0);

  //   invader.x = 0;
  //   invader.y = 0;
  //   images->invaders_m1 = invader;

  //   data = stbi_load("../Assets/Sprites/Invaders/invaderM2.png",
  //   &invader.width,
  //                    &invader.height, &invader.channels, 4);

  //   if (!data) {
  //     fprintf(stderr, "Failed to load image\n");
  //   }

  //   invader.image = XCreateImage(
  //       game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap,
  //       0, (char *)data, invader.width, invader.height, 32, 0);

  //   invader.x = 0;
  //   invader.y = 0;
  //   images->invaders_m2 = invader;

  //   data = stbi_load("../Assets/Sprites/Invaders/invaderS1.png",
  //   &invader.width,
  //                    &invader.height, &invader.channels, 4);

  //   if (!data) {
  //     fprintf(stderr, "Failed to load image\n");
  //   }

  //   invader.image = XCreateImage(
  //       game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap,
  //       0, (char *)data, invader.width, invader.height, 32, 0);

  //   invader.x = 0;
  //   invader.y = 0;
  //   images->invaders_s1 = invader;

  //   data = stbi_load("../Assets/Sprites/Invaders/invaderS2.png",
  //   &invader.width,
  //                    &invader.height, &invader.channels, 4);

  //   if (!data) {
  //     fprintf(stderr, "Failed to load image\n");
  //   }

  //   invader.image = XCreateImage(
  //       game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap,
  //       0, (char *)data, invader.width, invader.height, 32, 0);

  //   invader.x = 0;
  //   invader.y = 0;
  //   images->invaders_s2 = invader;
}

Images add_image(DisplayGame game) {
  Images images;

  ship(game, &images);
  invader(game, &images);
  bullet_add(game, &images);
  target_add(game, &images);
  add_distroy_invaders(game, &images);

  return images;
}

Media add_media(DisplayGame game) {
  Media media;

  media.images = add_image(game);
  return media;
}
