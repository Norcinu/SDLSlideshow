#include <iostream>
#include <memory>
#include "FileList.h"
#include "Visualisation.h"
#include <SDL2/SDL.h>
#undef main

using std::shared_ptr;
using std::cout;
using std::endl;

int main(int argc, const char *argv[]);

int main(int argc, const char *argv[])
{
    shared_ptr<FileList> _file_list(new FileList(argv[1], false));
    _file_list->scanDirectory();
    
    Visualisation vis;
    vis.init();
    
    auto files = _file_list->getFiles();
	for (auto it = files.begin(); it != files.end(); it++)
		if (!vis.loadSprite(*it))
			return 1;
    
    unsigned int id = 0;
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
                running = false;
            else if (event.key.keysym.sym == SDLK_d) {
                if (id < vis.getSpriteCount())
                    id++;
            }
            else if (event.key.keysym.sym == SDLK_a) {
                if (id > 0)
                    id--;
            }
        }
        
        vis.begin();
        vis.drawSprite(id);
        vis.end();
    }
    
    return 0;
}

