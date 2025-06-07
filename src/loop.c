#include "bullet.h"
#include "invaders.h"
#include "keyboard.h"
#include "ship.h"
#include <X11/X.h>
#include <X11/Xlib.h>
#include <loop.h>
#include <pthread.h>
#include <stdio.h>
#include <target.h>
#include <unistd.h>
void loop(DisplayGame game) {
  XEvent event;
  pthread_t thread;
  pthread_create(&thread, NULL, create_random, &game);
  while (1) {
    while (XPending(game.display)) {

      XNextEvent(game.display, &event);
      if (event.type == KeyPress) {
        KeySym key = XLookupKeysym(&event.xkey, 0);
        XClearWindow(game.display, game.window);
        dispatcher(&game, key);
      }
    }

    XClearWindow(game.display, game.window);

    set_ship(game);
    // run_target(&game);
    run_inv(&game);
    run_bullet(&game);

    XFlush(game.display);

    usleep(16000);
  }
}
