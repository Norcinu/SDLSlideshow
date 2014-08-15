#include <iostream>
#include <memory>
#include "FileList.h"
#include "Visualisation.h"
#include <SDL2/SDL.h>

using std::shared_ptr;

int main(int argc, const char * argv[])
{
    shared_ptr<FileList> _file_list(new FileList(argv[1], false));
    _file_list->scanDirectory();
    
    Visualisation vis;
    vis.init();
    
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
        }
        
        vis.begin();
        vis.end();
    }
    
    return 0;
}

