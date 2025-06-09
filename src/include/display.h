#ifndef DISPLAY_H
#define DISPLAY_H

#include <X11/Xft/Xft.h>
#include <X11/Xlib.h>
#include <time.h>

typedef struct {
	XImage *image;
	int width;
	int height;
	int channels;
	int x;
	int y;
} Image;

typedef struct {
	Image ship;
	Image bullet;
	Image target;
	Image distroy_invaders;

	Image invaders_l1;
	Image invaders_l2;
	Image invaders_m1;
	Image invaders_m2;
	Image invaders_s1;
	Image invaders_s2;
} Images;

typedef struct {
	Images images;
} Media;

typedef struct {
	int width;
	int height;
	int width_screen;
	int height_screen;
	int health;
	Display *display;
	Window window;
	GC gc;
	int screen;
	time_t time_start;
	float time_pass;
	Media media;
	XftFont *font;
	XftDraw *draw;
} DisplayGame;

DisplayGame configuration (int width,int height);

void FreeMemmory (DisplayGame game);

#endif
