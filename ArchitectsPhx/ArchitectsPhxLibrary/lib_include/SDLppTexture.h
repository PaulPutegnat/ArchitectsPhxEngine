#pragma once
#include <DLL_COMPILING.h>
#include <SDL.h>
#include <string>

class LIB_API SDLppRenderer;
class LIB_API SDLppSurface;

class LIB_API SDLppTexture
{
	public:
		SDLppTexture(const SDLppTexture&) = delete; // constructeur par copie
		SDLppTexture(SDLppTexture&& texture) noexcept; // constructeur par mouvement
		~SDLppTexture();

		SDL_Texture* GetHandle() const;

		SDLppTexture& operator=(const SDLppTexture&) = delete; // opérateur d'assignation par copie
		SDLppTexture& operator=(SDLppTexture&&) noexcept; // opérateur d'assignation par mouvement

		static SDLppTexture LoadFromFile(SDLppRenderer& renderer, const std::string& filepath);
		static SDLppTexture LoadFromSurface(SDLppRenderer& renderer, const SDLppSurface& surface);

	private:
		SDLppTexture(SDL_Texture* texture);

		SDL_Texture* m_texture;
};