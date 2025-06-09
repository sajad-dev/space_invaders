#include "display.h"
#include "loop.h"
#include "media.h"
#include <time.h>
int main() {
  time_t time_start = time(NULL);

  DisplayGame game = configuration(900, 900);
  game.media = add_media(game);
  game.time_start = time_start;
  game.time_pass = 0;
  game.health = 3;
  game.score = 0;
  game.hard_level = 0;

  loop(game);
  FreeMemmory(game);

  return 0;
}
