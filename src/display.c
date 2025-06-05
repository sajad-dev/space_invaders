#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <display.h>

DisplayGame configuration(int width,int height) {
  DisplayGame game;

  game.width = width;
  game.height = height;

  game.display = XOpenDisplay(NULL);

  game.screen = DefaultScreen(game.display);

  game.window = XCreateSimpleWindow(
      game.display, RootWindow(game.display, game.screen), 10, 10, game.width, game.height, 1,
      WhitePixel(game.display, game.screen),
      BlackPixel(game.display, game.screen));

  XSelectInput(game.display, game.window, ExposureMask | KeyPressMask);

  XMapWindow(game.display, game.window);

  game.gc = XCreateGC(game.display, game.window, 0, NULL);

  return game;
}

void FreeMemmory(DisplayGame game) {
  XFreeGC(game.display, game.gc);
  XDestroyWindow(game.display, game.window);
  XCloseDisplay(game.display);
  // XftFontClose(display, font);
  // XftDrawDestroy(game.draw);
}
