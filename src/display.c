#include "bullet.h"
#include "distroy.h"
#include "invaders.h"
#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <display.h>

DisplayGame configuration(int width, int height) {
  DisplayGame game;

  game.width = width;
  game.height = height - 80;

  game.width_screen = width;
  game.height_screen = height;

  game.display = XOpenDisplay(NULL);

  game.screen = DefaultScreen(game.display);

  game.window = XCreateSimpleWindow(
      game.display, RootWindow(game.display, game.screen), 10, 10, game.width_screen,
      game.height_screen, 1, WhitePixel(game.display, game.screen),
      BlackPixel(game.display, game.screen));

  XSelectInput(game.display, game.window, ExposureMask | KeyPressMask);

  XMapWindow(game.display, game.window);

  game.gc = XCreateGC(game.display, game.window, 0, NULL);

  XftDraw *draw = NULL;

  game.font = XftFontOpenName(game.display, game.screen, "DejaVu Sans-15");
  game.draw = XftDrawCreate(game.display, game.window,
                            DefaultVisual(game.display, game.screen),
                            DefaultColormap(game.display, game.screen));

  return game;
}

void FreeMemmory(DisplayGame game) {
  XFreeGC(game.display, game.gc);
  XDestroyWindow(game.display, game.window);
  XCloseDisplay(game.display);
  free(invaders);
  free(bullet);
  free(distroy_list);
  // free(target);
  XftFontClose(game.display, game.font);
  XftDrawDestroy(game.draw);
}
