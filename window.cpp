#include "window.h"

// Will wait until a key is pressed
Key Window::getKeyPress() {
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            quit = true;
            break;

        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
                quit = true;
                return Key::ESCAPE;
                break;

            case SDLK_UP:
                return Key::UP;
                break;

            case SDLK_DOWN:
                return Key::DOWN;
                break;

            case SDLK_LEFT:
                return Key::LEFT;
                break;

            case SDLK_RIGHT:
                return Key::RIGHT;
                break;

            default:
                break;
            }

        default:
            break;
        }
    }

    return Key::NONE;
}

int Window::normCoord(double d) {
    return static_cast<int>(d * WINDOW_HEIGHT / 0.8);
}

void Window::drawPoints(const Cube& cube) {
    const std::vector<Point2D>& points = cube.getPoints();
    for (const Point2D& p : points) {
        SDL_RenderDrawPoint(renderer, normCoord(p.x), normCoord(p.y));
    }
    SDL_RenderPresent(renderer);
}

void Window::cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}