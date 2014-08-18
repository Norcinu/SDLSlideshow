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

