#include "clock.h"
#include <X11/Xft/Xft.h>
#include <stdio.h>
void render_clock(DisplayGame game) {

  int h = (int)game.time_pass / 3600;
  int m = ((int)game.time_pass % 3600) / 60;
  int s = (int)game.time_pass % 60;
  char time_f[20];
  sprintf(time_f, "%d:%d:%d", h, m, s);
  XRenderColor render_color = {0xffff, 0xffff, 0xffff, 0xffff};
  XftColor xft_color;

  XftColorAllocValue(game.display, DefaultVisual(game.display, game.screen),
                     DefaultColormap(game.display, game.screen), &render_color,
                     &xft_color);

  XftDrawStringUtf8(game.draw, &xft_color, game.font, game.width - 80,
                    game.height_screen - 30, (XftChar8 *)time_f,
                    strlen(time_f));

  XftColorFree(game.display, DefaultVisual(game.display, game.screen),
               DefaultColormap(game.display, game.screen), &xft_color);
}
