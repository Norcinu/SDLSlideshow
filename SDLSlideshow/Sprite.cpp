#include "Sprite.hpp"
#include <iostream>

Sprite::Sprite(SDL_Renderer *r) :
    _texture(nullptr),
    _renderer(r),
    _x(0),
    _y(0)
{
}

Sprite::~Sprite()
{
    if (_texture) {
        SDL_DestroyTexture(_texture);
        _texture = nullptr;
    }
}

bool Sprite::init(const std::string& filename)
{
    if (filename == "")
        return false;
    
    SDL_Surface *surface = IMG_Load(filename.c_str());
    if (surface == nullptr) {
        std::cerr << IMG_GetError() << std::endl;
        return false;
    }
    else {
        _texture = SDL_CreateTextureFromSurface(_renderer, surface);
        if (_texture == nullptr) {
            SDL_FreeSurface(surface);
            return false;
        }
        SDL_FreeSurface(surface);
    }
    return true;
}

void Sprite::render(const int x, const int y)
{
    SDL_RenderCopy(_renderer, _texture, nullptr, nullptr);
}