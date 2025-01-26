#ifndef WINDOW_H
#define WINDOW_H

#include <stdbool.h>

bool create_window(const char *title, int width, int height);
void destroy_window();
bool window_is_open();
void poll_events();
void close_window();

#endif
