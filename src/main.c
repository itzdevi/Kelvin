#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <glad/glad.h>
#include <SDL2/SDL.h>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Unable to initialize SDL video! %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window* window = SDL_CreateWindow("Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        800, 600,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL
    );

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    SDL_GLContext context = SDL_GL_CreateContext(window);

    if (!context) {
        printf("Cannot create OpenGL context! %s\n", SDL_GetError());
        exit(1);
    }

    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        printf("Unable to initialize GLAD!\n");
        exit(1);
    }

    bool shouldQuit = false;
    while (!shouldQuit) {
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
            shouldQuit = true;

        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.07, 0.07, 0.07, 1.0);
        
        SDL_GL_SwapWindow(window);
    }

    SDL_Quit();
    exit(0);
}
