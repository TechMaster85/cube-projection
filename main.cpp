#include <iostream>

#include "cube.h"
#include "window.h"

int main() {
    Window window;
    Cube cube;

    window.updateWindow();
    cube.reset();

    const double ANGLE = M_PI / 12;

    while (!window.hasQuit()) {
        // Wait for a key press (escape or pressing exit on window will activate hasQuit())
        Key k = window.getKeyPress();

        // Transform the cube based on the key press (to be implemented in cube.cpp)
        switch (k) {
        case Key::NONE:
            break;

        case Key::UP:
            std::cout << "Key UP pressed\n";
            cube.transformed_points(ANGLE, 0);
            cube.printRotation();
            break;

        case Key::DOWN:
            std::cout << "Key DOWN pressed\n";
            cube.transformed_points(-ANGLE, 0);
            cube.printRotation();
            break;

        case Key::LEFT:
            std::cout << "Key LEFT pressed\n";
            cube.transformed_points(0, -ANGLE);
            cube.printRotation();
            break;

        case Key::RIGHT:
            std::cout << "Key RIGHT pressed\n";
            cube.transformed_points(0, ANGLE);
            cube.printRotation();
            break;

        case Key::ESCAPE:
            std::cout << "Key ESCAPE pressed\n";
            break;   // Should automatically exit program
        }

        // Feed the matrix into a draw function
        window.drawPoints(cube);
    }

    return 0;
}