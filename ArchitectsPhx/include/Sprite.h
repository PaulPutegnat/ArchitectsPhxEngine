#pragma once

#include <SDL.h>

class SDLppRenderer;
class SDLppTexture;

class Sprite // Une portion d'une texture 
{
	public:
		Sprite(sonst SDLppTexture& texture, const SDL_Rect& rect);
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