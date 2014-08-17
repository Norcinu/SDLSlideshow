#ifndef VISUALISATION_H
#define VISUALISATION_H

#include <string>
#include <vector>

using std::vector;

struct SDL_Window;
struct SDL_Renderer;

class Sprite;

class Visualisation
{
public:
    Visualisation();
    ~Visualisation();
    
    bool init();
    bool loadSprite(const std::string &filename);
    void begin();
    void drawSprite(const int id);
    void end();
    
    bool getFullScreen() const { return _fullscreen; }
    void setFullScreen(const bool fs) { _fullscreen = fs; }
    
private:
    bool _fullscreen;
    unsigned int _screen_height;
    unsigned int _screen_width;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    vector<Sprite *> _sprites;
};

#endif
