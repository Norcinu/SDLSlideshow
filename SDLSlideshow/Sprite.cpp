#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer *r) : _texture(nullptr), _renderer(r)
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
    if (surface == nullptr)
        return false;
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
