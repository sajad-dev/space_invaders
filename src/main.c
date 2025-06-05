#include "display.h"
#include "loop.h"
#include "media.h"
int main() {
  DisplayGame game = configuration(900,900);
  game.media = add_media(game);
  loop(game);
  FreeMemmory(game);

  return 0;
}
