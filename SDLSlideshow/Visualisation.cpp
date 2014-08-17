#include "Visualisation.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Sprite.hpp"

Visualisation::Visualisation()
{
    _fullscreen = true;
    _screen_height = 480;
    _screen_height = 640;
    _renderer = nullptr;
    _window = nullptr;
}

Visualisation::~Visualisation()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    
    _renderer = nullptr;
    _window = nullptr;
    
    IMG_Quit();
    SDL_Quit();
}

bool Visualisation::init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        return false;
    if (IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG) == -1)
        return false;
    
    uint window_args = 0;
    if (_fullscreen) {
        window_args = SDL_WINDOW_FULLSCREEN_DESKTOP;
    } else {
        window_args = 0; //TODO.
    }
    
    SDL_Rect dim;
    SDL_GetDisplayBounds(0, &dim);
    _screen_height = dim.h;
    _screen_width = dim.w;
    _window = SDL_CreateWindow("SDL Slideshow", 10, 10, _screen_width, _screen_height, SDL_WINDOW_OPENGL);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawColor(_renderer, 255, 0, 128, 255);
    
    return true;
}

bool Visualisation::loadSprite(const std::string &filename)
{
    Sprite *sprite = new Sprite(_renderer);
    if (!sprite->init(filename)) {
        delete sprite;
        return false;
    }
    
    _sprites.push_back(sprite);
    
    return true;
}

void Visualisation::begin()
{
    SDL_SetRenderDrawColor(_renderer, 255, 0, 128, 255);
    SDL_RenderClear(_renderer);
}

void Visualisation::end()
{
    SDL_RenderPresent(_renderer);
}

void Visualisation::drawSprite(const int id)
{
    
}