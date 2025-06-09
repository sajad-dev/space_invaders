#include "display.h"
#include <score.h>
int score;
void render_score(DisplayGame game) {

  char score_wr[20];
  sprintf(score_wr, "%d", score);
  XRenderColor render_color = {0xffff, 0xffff, 0xffff, 0xffff};
  XftColor xft_color;

  XftColorAllocValue(game.display, DefaultVisual(game.display, game.screen),
                     DefaultColormap(game.display, game.screen), &render_color,
                     &xft_color);

  XftDrawStringUtf8(game.draw, &xft_color, game.font, game.width - 200,
                    game.height_screen - 30, (XftChar8 *)score_wr,
                    strlen(score_wr));

  XftColorFree(game.display, DefaultVisual(game.display, game.screen),
               DefaultColormap(game.display, game.screen), &xft_color);
}
