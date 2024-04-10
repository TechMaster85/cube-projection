#ifndef WINDOW_H
#define WINDOW_H

#include <vector>

#include <SDL2/SDL.h>

#include "cube.h"

enum class Key { NONE, ESCAPE, UP, DOWN, LEFT, RIGHT };

class Window {
private:
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 640;
    // const double BORDER = 0.8;   // 0 means the cube is one dot, 1 means the original cube uses the entire screen

    SDL_Window* window = SDL_CreateWindow("Cube Projection", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

    SDL_Event e {};
    bool quit = false;


public:
    Key getKeyPress();
    bool hasQuit() const { return quit; };

    int normCoord(double d);
    void drawPoints(const Cube& cube);
    void updateWindow() const { SDL_RenderPresent(renderer); }

    void cleanup();
};


#endif