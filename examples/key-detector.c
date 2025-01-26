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
    }

    destroy_window();
    return 0;
}
