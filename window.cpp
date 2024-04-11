#include "window.h"

#include <iostream>

#include <SDL2/SDL_render.h>

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
    return static_cast<int>((WINDOW_HEIGHT / 2) - (d * WINDOW_HEIGHT * 0.4));
}

void Window::drawPoint(Point2D p, int thickness) {
    // Draw a square block of pixels around (x, y)
    for (int i = -thickness; i <= thickness; ++i) {
        for (int j = -thickness; j <= thickness; ++j) {
            SDL_RenderDrawPoint(renderer, normCoord(p.x) + i, normCoord(p.y) + j);
        }
    }
}

void Window::drawPoints(const Cube& cube) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    const std::vector<Point2D>& points = cube.getPoints();
    for (const Point2D& p : points) {
        drawPoint(p, 5);
    }
    SDL_RenderPresent(renderer);
}

void Window::cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}