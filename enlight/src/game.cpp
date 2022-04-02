#define SDL_MAIN_HANDLED
#include <string>
#include "..\include\SDL.h"
#include <iostream>

// g++ game.cpp -o game.exe -lmingw32 -L ..\lib -lSDL2main -lSDL2
// .dll must be in src folder
// .lib must be in lib folder

using namespace std;

int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window1;
    window1 =  SDL_CreateWindow("Enlight", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_SHOWN);

    if(window1 == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }   

    SDL_Renderer *renderer = SDL_CreateRenderer(window1, -1, 0);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_Event event1;

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    bool out = true;
    while(out) {
        while(SDL_PollEvent(&event1)) {
            if(event1.type == SDL_QUIT) {
                out = false;
            }
            if(event1.type == SDL_KEYDOWN) {
                continue;
            }
            if(event1.type == SDL_MOUSEBUTTONDOWN) {
                continue;
            }
        }
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window1);
    SDL_Quit();
    return 0;

}