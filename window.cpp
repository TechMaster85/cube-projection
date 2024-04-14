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

void Window::drawLine(const Line& line, int thickness) {
    const int x1 = static_cast<int>(normCoord(line.x1));
    const int y1 = static_cast<int>(normCoord(line.y1));
    const int x2 = static_cast<int>(normCoord(line.x2));
    const int y2 = static_cast<int>(normCoord(line.y2));

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for (int i = -thickness; i <= thickness; ++i) {
        for (int j = -thickness; j <= thickness; ++j) {
            SDL_RenderDrawLine(renderer, x1 + i, y1 + j, x2 + i, y2 + j);
        }
    }
}

void Window::drawLines(const Cube& cube) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    const std::vector<Point2D>& points = cube.getPoints();
    drawLine(Line { points.at(0).x, points.at(0).y, points.at(1).x, points.at(1).y }, 2);
    drawLine(Line { points.at(1).x, points.at(1).y, points.at(4).x, points.at(4).y }, 2);
    drawLine(Line { points.at(4).x, points.at(4).y, points.at(2).x, points.at(2).y }, 2);
    drawLine(Line { points.at(2).x, points.at(2).y, points.at(0).x, points.at(0).y }, 2);
    drawLine(Line { points.at(3).x, points.at(3).y, points.at(6).x, points.at(6).y }, 2);
    drawLine(Line { points.at(6).x, points.at(6).y, points.at(7).x, points.at(7).y }, 2);
    drawLine(Line { points.at(7).x, points.at(7).y, points.at(5).x, points.at(5).y }, 2);
    drawLine(Line { points.at(5).x, points.at(5).y, points.at(3).x, points.at(3).y }, 2);
    drawLine(Line { points.at(0).x, points.at(0).y, points.at(3).x, points.at(3).y }, 2);
    drawLine(Line { points.at(1).x, points.at(1).y, points.at(6).x, points.at(6).y }, 2);
    drawLine(Line { points.at(4).x, points.at(4).y, points.at(7).x, points.at(7).y }, 2);
    drawLine(Line { points.at(2).x, points.at(2).y, points.at(5).x, points.at(5).y }, 2);

    SDL_RenderPresent(renderer);
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

    drawLines(cube);
}

void Window::cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}