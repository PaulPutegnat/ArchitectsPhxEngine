#include <iostream>
#include <SDL.h>
#include "SDLpp.h"
#include "SDLppWindow.h"
#include "SDLppRenderer.h"
#include "SDLppTexture.h"
#include "Transform.h"

//#include "Sprite.h"

/*
   _            _     _ _            _         ___ _
  /_\  _ __ ___| |__ (_| |_ ___  ___| |_ ___  / _ | |__ __  __
 //_\\| '__/ __| '_ \| | __/ _ \/ __| __/ __|/ /_)| '_ \\ \/ /
/  _  | | | (__| | | | | ||  __| (__| |_\__ / ___/| | | |>  <
\_/ \_|_|  \___|_| |_|_|\__\___|\___|\__|___\/    |_| |_/_/\_\

*/

int main(int argc, char** argv)
{
    SDLpp sdl;
    //testsdf
    SDLppWindow window("ArchitectsPhx", 1280, 720);
    SDLppRenderer renderer(window);

    SDLppTexture theirDebutAlbum = SDLppTexture::LoadFromFile(renderer, "assets/KIMBABIG.jpg");

    SDL_Rect spriteRect = { 0, 0, 140, 140 };
    //Sprite sprite(theirDebutAlbum, spriteRect);

    bool isOpen = true;
    while (isOpen)
    {
        SDL_Event event;
        while (SDLpp::PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isOpen = false;
        }

        renderer.SetDrawColor(127, 0, 127, 255);
        renderer.Clear();

        SDL_Rect rect;
        rect.x = 147;
        rect.y = 257;
        rect.w = 1422 / 4;
        rect.h = 1347 / 4;

        renderer.RenderCopy(theirDebutAlbum, rect);
        renderer.Present();
    }

    Tranform transform;
    Vector2 result;
    transform.SetPosition(Vector2(42.2f, -6.f));
    transform.SetRotation(-270.f);
    transform.SetScale(Vector2(0.5f, 2.f));

    result = transform.TransformPoint(Vector2(0.f, 0.f));
    std::cout << result.x << "   " << result.y << std::endl;
    result = transform.TransformPoint(Vector2(10.f, 0.f));
    std::cout << result.x << "   " << result.y << std::endl;
    result = transform.TransformPoint(Vector2(0.f, 10.f));
    std::cout << result.x << "   " << result.y << std::endl;
    result = transform.TransformPoint(Vector2(21.f, -3.f));
    std::cout << result.x << "   " << result.y << std::endl;

    transform.SetScale(Vector2(0.5f, -2.f));
    result = transform.TransformPoint(Vector2(-42.f, -42.f));
    std::cout << result.x << "   " << result.y << std::endl;

    return 0;
}
