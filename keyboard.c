#include "keyboard.h"

#ifdef _WIN32
#include <windows.h>

static bool keys[256];

bool key_pressed(int key) {
    return GetAsyncKeyState(key) & 0x8000;
}

#else
#error "Unsupported platform"
#endif
