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

        float current_time = (SDL_GetTicks() - start_time) / 1000.0f;

        for (int y = 0; y < HEIGHT; ++y) {
            for (int x = 0; x < WIDTH; ++x) {
                float r,g,b;

                shader_logic(static_cast<float>(x), static_cast<float>(y), current_time, r, g, b);

                uint8_t ir = static_cast<uint8_t>(r * 255.0f);
                uint8_t ig = static_cast<uint8_t>(g * 255.0f);
                uint8_t ib = static_cast<uint8_t>(b * 255.0f);

                uint32_t pixel_color = (255 << 24) | (ir << 16) | (ig << 8) | ib;

                pixels[y * WIDTH + x] = pixel_color;
            }
        }

        SDL_UpdateTexture(framebuffer_texture, NULL, pixels, WIDTH * sizeof(uint32_t));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, framebuffer_texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    delete[] pixels;
    SDL_DestroyTexture(framebuffer_texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
