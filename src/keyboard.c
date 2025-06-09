#include "bullet.h"
#include "ship.h"
#include <X11/X.h>
#include <X11/Xutil.h>
#include <keyboard.h>

void dispatcher(DisplayGame *game, KeySym key) {
  switch (key) {
  case XK_Right:
    right_ship(game);
    set_ship(*game);
    break;
  case XK_Left:
    left_ship(game);
    set_ship(*game);
    break;
  case XK_space:
    shut(*game, game->media.images.ship.x + (game->media.images.ship.width / 2),
         game->media.images.ship.y);
    break;
  };
}
