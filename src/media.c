#include "display.h"
#include <media.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void ship(DisplayGame game, Images *images) {
  Image ship_image;

  unsigned char *data =
      stbi_load("../Assets/Sprites/player2.png", &ship_image.width,
                &ship_image.height, &ship_image.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  ship_image.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, ship_image.width, ship_image.height, 32, 0);

  ship_image.x = game.width / 2 - 50;
  ship_image.y = game.height - 50;
  images->ship = ship_image;
}

void invader(DisplayGame game, Images *images) {
  Image invader;

  unsigned char *data =
      stbi_load("../Assets/Sprites/Invaders/invaderL1.png", &invader.width,
                &invader.height, &invader.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  invader.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, invader.width, invader.height, 32, 0);

  invader.x = 0;
  invader.y = 0;
  images->invaders_l1 = invader;

  data = stbi_load("../Assets/Sprites/Invaders/invaderL2.png", &invader.width,
                   &invader.height, &invader.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  invader.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, invader.width, invader.height, 32, 0);

  invader.x = 0;
  invader.y = 0;
  images->invaders_l2 = invader;

  data = stbi_load("../Assets/Sprites/Invaders/invaderM1.png", &invader.width,
                   &invader.height, &invader.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  invader.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, invader.width, invader.height, 32, 0);

  invader.x = 0;
  invader.y = 0;
  images->invaders_m1 = invader;

  data = stbi_load("../Assets/Sprites/Invaders/invaderM2.png", &invader.width,
                   &invader.height, &invader.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  invader.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, invader.width, invader.height, 32, 0);

  invader.x = 0;
  invader.y = 0;
  images->invaders_m2 = invader;

  data = stbi_load("../Assets/Sprites/Invaders/invaderS1.png", &invader.width,
                   &invader.height, &invader.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  invader.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, invader.width, invader.height, 32, 0);

  invader.x = 0;
  invader.y = 0;
  images->invaders_s1 = invader;

  data = stbi_load("../Assets/Sprites/Invaders/invaderS2.png", &invader.width,
                   &invader.height, &invader.channels, 4);

  if (!data) {
    fprintf(stderr, "Failed to load image\n");
  }

  invader.image = XCreateImage(
      game.display, DefaultVisual(game.display, game.screen), 24, ZPixmap, 0,
      (char *)data, invader.width, invader.height, 32, 0);

  invader.x = 0;
  invader.y = 0;
  images->invaders_s2 = invader;
}

Images add_image(DisplayGame game) {
  Images images;

  ship(game, &images);
  invader(game, &images);


  return images;
}

Media add_media(DisplayGame game) {
  Media media;

  media.images = add_image(game);
  return media;
}
