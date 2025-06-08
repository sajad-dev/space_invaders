#include "footer.h"
#include "clock.h"
void draw_footer(DisplayGame game) {
  Colormap colormap = DefaultColormap(game.display, game.screen);
  XColor green_color;
  XParseColor(game.display, colormap, "#00FF00", &green_color);
  XAllocColor(game.display, colormap, &green_color);
  XSetForeground(game.display, game.gc, green_color.pixel);

  XSetLineAttributes(game.display, game.gc, 3, LineSolid, CapButt, JoinMiter);

  XDrawLine(game.display, game.window, game.gc, 0, game.height_screen - 70,
            game.width_screen, game.height_screen - 70);
  render_clock(game);
}
