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

void Window::cleanup() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}