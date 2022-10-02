#include <iostream>
#include <SDL.h>
#include "SDLpp.h"
#include "SDLppWindow.h"
#include "SDLppRenderer.h"
#include "SDLppTexture.h"
#include "Sprite.h"
#include "Vector2.h"

/*
   _            _     _ _            _         ___ _
  /_\  _ __ ___| |__ (_| |_ ___  ___| |_ ___  / _ | |__ __  __
 //_\\| '__/ __| '_ \| | __/ _ \/ __| __/ __|/ /_)| '_ \\ \/ /
/  _  | | | (__| | | | | ||  __| (__| |_\__ / ___/| | | |>  <
\_/ \_|_|  \___|_| |_|_|\__\___|\___|\__|___\/    |_| |_/_/\_\

*/

int main(int argc, char** argv)
{
    Vector2 vec1 = Vector2(3, 4);
    Vector2 vec2 = Vector2(7, 6);

    vec1 += vec2;

    std::cout << vec1.pos_x << std::endl;

    /*
    SDLpp sdl;

    float delay;
    int rect_x = 0;
    int rect_y = 32;
    int pos_x = 32;
    
    SDLppWindow window("ArchitectsPhx", 1280, 720);
    SDLppRenderer renderer(window);

    SDLppTexture runner = SDLppTexture::LoadFromFile(renderer, "assets/runner.png");
    Sprite sprite(runner);
    sprite.Resize(256, 256);

    sprite.SetRect(SDL_Rect{ 0, 0, 32, 32 });

    Uint64 lastUpdate = SDL_GetPerformanceCounter();

    int frameIndex = 0;
    int frameCount = 5;
    float timer = 0.0f;

    bool isOpen = true;
    while (isOpen)
    {
        Uint64 now = SDL_GetPerformanceCounter();
        float deltaTime = (float)(now - lastUpdate) / SDL_GetPerformanceFrequency();
        lastUpdate = now;

        timer += deltaTime;
        if (timer > 0.1f)
        {
            timer -= 0.1f;
            frameIndex++;
            if (frameIndex >= frameCount)
                frameIndex = 0;

            sprite.SetRect({ frameIndex * 32, 0, 32, 32 });

            std::cout << frameIndex << std::endl;
        }

        SDL_Event event;
        while (SDLpp::PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isOpen = false;
        }

        renderer.SetDrawColor(127, 0, 127, 255);
        renderer.Clear();

        sprite.Draw(renderer, 147, 257);
        renderer.Present();
    }

    return 0;
    */

}
