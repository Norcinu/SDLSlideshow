#ifndef SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Sprite
{
public:
    Sprite(SDL_Renderer *r);
    ~Sprite();

    bool init(const std::string& filename);
    
private:
    SDL_Renderer *_renderer;
    SDL_Texture *_texture;
    int x;
    int y;
    std::string _filename;
};

#endif
