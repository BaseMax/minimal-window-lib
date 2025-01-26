#include "window.h"
#include "keyboard.h"
#include "mouse.h"

int main() {
    if (!create_window("Test Window", 800, 600)) {
        return -1;
    }

    while (window_is_open()) {
        poll_events();

        if (key_pressed(KEY_ESCAPE)) {
            close_window();
        }

        if (mouse_button_pressed(MOUSE_BUTTON_LEFT)) {
            printf("Left mouse button clicked at (%d, %d)\n", mouse_x(), mouse_y());
        }
    }

    destroy_window();
    return 0;
}
