#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include <algorithm>

const int WIDTH = 800;
const int HEIGHT = 600;

void shader_logic(float x, float y, float current_time, float& r, float& g, float& b){
    float norm_x = x / static_cast<float>(WIDTH);
    float norm_y = y / static_cast<float>(HEIGHT);

    r = norm_x;
    g = norm_y;
    b = (1.0f + std::sin(current_time * 3.0f)) * 0.5f;

    r = std::max(0.0f, std::min(1.0f, r));
    g = std::max(0.0f, std::min(1.0f, g));
    b = std::max(0.0f, std::min(1.0f, b));
}

int main(int argc, char* argv[]){

    SDL_Window* window = SDL_CreateWindow(
            "Nyph", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN
            );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* framebuffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH, HEIGHT
    );

    uint32_t* pixels = new uint32_t[WIDTH * HEIGHT];
    bool is_running = true;
    SDL_Event event;
    uint32_t start_time = SDL_GetTicks();

    while (is_running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                is_running= false;
            }
        }
    }

    return 0;
}
