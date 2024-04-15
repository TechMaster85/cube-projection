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

Line pointsToLine(const std::vector<Point2D>& points, int ind1, int ind2) {
    return Line { points.at(ind1).x, points.at(ind1).y, points.at(ind2).x, points.at(ind2).y };
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
    drawLine(pointsToLine(points, 0, 1), 2);
    drawLine(pointsToLine(points, 1, 4), 2);
    drawLine(pointsToLine(points, 4, 2), 2);
    drawLine(pointsToLine(points, 2, 0), 2);
    drawLine(pointsToLine(points, 3, 6), 2);
    drawLine(pointsToLine(points, 6, 7), 2);
    drawLine(pointsToLine(points, 7, 5), 2);
    drawLine(pointsToLine(points, 5, 3), 2);
    drawLine(pointsToLine(points, 0, 3), 2);
    drawLine(pointsToLine(points, 1, 6), 2);
    drawLine(pointsToLine(points, 4, 7), 2);
    drawLine(pointsToLine(points, 2, 5), 2);

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