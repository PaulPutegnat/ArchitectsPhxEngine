#pragma once
#include <DLL_COMPILING.h>
#include <SDL.h>

class LIB_API SDLppRenderer;
class LIB_API SDLppTexture;

class LIB_API Sprite // Une portion d'une texture 
{
	public:
		Sprite(const SDLppTexture& texture, const SDL_Rect& rect);
		Sprite(const Sprite&) = default;
		Sprite(Sprite&&) = default;
		~Sprite() = default;

		void Draw(SDLppRenderer& renderer, int x, int y);

		Sprite& operator=(const Sprite&) = delete;
		Sprite& operator=(Sprite&&) = delete;

	private:
		SDLppTexture& m_texture;
		SDL_Rect m_rect;
};