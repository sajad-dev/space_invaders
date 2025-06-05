#include "keyboard.h"
#include "ship.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <loop.h>

void loop(DisplayGame game) {
  XEvent event;
  while (1) {
    XNextEvent(game.display, &event);
    if (event.type == Expose) {
      set_ship(game);

      XPutImage(game.display, game.window, DefaultGC(game.display, game.screen),
                game.media.images.invaders_m1.image, 0, 0, 100, 100,
                game.media.images.invaders_m1.width,
                game.media.images.invaders_m1.height);
      
      XFlush(game.display);
    }

    if (event.type == KeyPress) {
      KeySym key = XLookupKeysym(&event.xkey, 0);
      XClearWindow(game.display, game.window);

      dispatcher(&game, key);
      XFlush(game.display);
    }
  }
}
