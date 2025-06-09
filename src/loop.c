#include "bullet.h"
#include "distroy.h"
#include "clock.h"
#include "distroy.h"
#include "footer.h"
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

void end_game(DisplayGame *game) {
  XClearWindow(game->display, game->window);

  char game_over_text[] = "GAME OVER";
  char score_text[50];
  char restart_text[] = "Press 'R' to restart or 'Q' to quit";

  snprintf(score_text, sizeof(score_text), "Final Score: %d", game->score);

  XSetForeground(game->display, game->gc, WhitePixel(game->display, 0));

  int window_width = game->width_screen;
  int window_height = game->height_screen;

  XDrawString(game->display, game->window, game->gc, window_width / 2 - 50,
              window_height / 2 - 40, game_over_text, strlen(game_over_text));

  XDrawString(game->display, game->window, game->gc, window_width / 2 - 60,
              window_height / 2 - 10, score_text, strlen(score_text));

  XDrawString(game->display, game->window, game->gc, window_width / 2 - 120,
              window_height / 2 + 20, restart_text, strlen(restart_text));

  XFlush(game->display);

  XEvent event;
  while (1) {
    XNextEvent(game->display, &event);
    if (event.type == KeyPress) {
      KeySym key = XLookupKeysym(&event.xkey, 0);

      if (key == XK_q || key == XK_Q) {
        printf("Thanks for playing!\n");
        exit(0);
      } else if (key == XK_r || key == XK_R) {
        printf("Restarting game...\n");
        game->health = 3;
        game->score = 0;
        game->time_pass = 0;
        game->hard_level = 0;
        count_invaders = 0;
        capcity_invaders = 0;
        count_bullet = 0;
        capcity_bullet = 0;
        loop(*game);

        break;
      }
    }
  }
}

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
    run_inv(&game);
    distroy_invaders(game);
    run_bullet(&game);
    deailing(&game);
    render_clock(game);
    draw_footer(game);
    if (game.health <= 0) {
      end_game(&game);
    }
    XFlush(game.display);
    game.time_pass += 1600.0 / (100000);
    usleep(16000);
  }
  printf("end\n");
}
