#include "mouse.h"

#ifdef _WIN32
#include <windows.h>

static POINT mouse_position;

bool mouse_button_pressed(int button) {
    switch (button) {
        case MOUSE_BUTTON_LEFT:
            return GetAsyncKeyState(VK_LBUTTON) & 0x8000;
        case MOUSE_BUTTON_RIGHT:
            return GetAsyncKeyState(VK_RBUTTON) & 0x8000;
        case MOUSE_BUTTON_MIDDLE:
            return GetAsyncKeyState(VK_MBUTTON) & 0x8000;
        default:
            return false;
    }
}

int mouse_x() {
    GetCursorPos(&mouse_position);
    return mouse_position.x;
}

int mouse_y() {
    GetCursorPos(&mouse_position);
    return mouse_position.y;
}

#else
#error "Unsupported platform"
#endif
