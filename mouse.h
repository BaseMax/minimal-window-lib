#ifndef MOUSE_H
#define MOUSE_H

#include <stdbool.h>

#define MOUSE_BUTTON_LEFT   0
#define MOUSE_BUTTON_RIGHT  1
#define MOUSE_BUTTON_MIDDLE 2

bool mouse_button_pressed(int button);
int mouse_x();
int mouse_y();

#endif
