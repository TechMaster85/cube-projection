#include <iostream>

#include "cube.h"
#include "window.h"

int main() {
    Window window;
    Cube cube;

    window.updateWindow();

    while (!window.hasQuit()) {
        // Wait for a key press (escape or pressing exit on window will activate hasQuit())
        Key k = window.getKeyPress();

        // Transform the cube based on the key press (to be implemented in cube.cpp)
        switch (k) {
        case Key::NONE:
            break;

        case Key::UP:
            std::cout << "Key UP pressed\n";
            break;

        case Key::DOWN:
            std::cout << "Key DOWN pressed\n";
            break;

        case Key::LEFT:
            std::cout << "Key LEFT pressed\n";
            break;

        case Key::RIGHT:
            std::cout << "Key RIGHT pressed\n";
            break;

        case Key::ESCAPE:
            std::cout << "Key ESCAPE pressed\n";
            break;   // Should automatically exit program
        }

        // Feed the matrix into a draw function
    }

    return 0;
}