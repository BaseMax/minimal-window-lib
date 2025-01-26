#include "window.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

static HWND hwnd;
static bool is_open = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            is_open = false;
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

bool create_window(const char *title, int width, int height) {
    HINSTANCE hInstance = GetModuleHandle(NULL);

    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MinimalWindowClass";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(0, "MinimalWindowClass", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                          CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);

    if (!hwnd) {
        return false;
    }

    is_open = true;
    return true;
}

void destroy_window() {
    DestroyWindow(hwnd);
}

bool window_is_open() {
    return is_open;
}

void poll_events() {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void close_window() {
    is_open = false;
}

#else
#error "Unsupported platform"
#endif
