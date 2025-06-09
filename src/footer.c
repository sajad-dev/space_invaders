#include "footer.h"
#include "clock.h"
#include "score.h"


static unsigned long green_pixel = 0;
static int color_initialized = 0;

void init_footer_colors(DisplayGame *game) {
  if (!color_initialized) {
    Colormap colormap = DefaultColormap(game->display, game->screen);
    XColor green_color;
    if (XParseColor(game->display, colormap, "#00FF00", &green_color)) {
      if (XAllocColor(game->display, colormap, &green_color)) {
        green_pixel = green_color.pixel;
        color_initialized = 1;
      }
    }
    if (!color_initialized) {
      green_pixel = WhitePixel(game->display, game->screen);
      color_initialized = 1;
    }
  }
}

void draw_footer(DisplayGame game) {
  init_footer_colors(&game);

  XSetForeground(game.display, game.gc, green_pixel);
  XSetLineAttributes(game.display, game.gc, 1, LineSolid, CapButt, JoinMiter);

  XDrawLine(game.display, game.window, game.gc, 0, game.height_screen - 70,
            game.width_screen, game.height_screen - 70);

  render_clock(game);
  render_score(game);

  for (int i = 0; i < game.health; i++) {
    XPutImage(game.display, game.window, game.gc, game.media.images.ship.image,
              0, 0, 10 + (i * (game.media.images.ship.width + 2)),
              game.height_screen - 50, game.media.images.ship.width,
              game.media.images.ship.height);
  }
}
