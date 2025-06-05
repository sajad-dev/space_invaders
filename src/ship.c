#include <ship.h>

void set_ship(DisplayGame game) {
  XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
            game.media.images.ship.image, 0, 0, game.media.images.ship.x,
            game.media.images.ship.y, game.media.images.ship.width,
            game.media.images.ship.height);
};

void right_ship(DisplayGame *game) {
  if (game->media.images.ship.x > game->width+ game->media.images.ship.width - 20) {
    game->media.images.ship.x = -game->media.images.ship.width;
  } else {
    game->media.images.ship.x += 10;
  }
};
void left_ship(DisplayGame *game) {
  if (game->media.images.ship.x < -game->media.images.ship.width + 20) {
    game->media.images.ship.x = game->width;

  } else {
    game->media.images.ship.x -= 10;
  }
};
