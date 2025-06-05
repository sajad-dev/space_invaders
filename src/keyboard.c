#include "ship.h"
#include <X11/X.h>
#include <X11/Xutil.h>
#include <keyboard.h>
#include <stdio.h>

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
  };
}
