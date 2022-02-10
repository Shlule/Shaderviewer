#include "RendererSDL.h"
#include"Log.h"

RendererSDL::RendererSDL() : SDLRenderer(nullptr) {

}
bool RendererSDL::Initialize(Window& window) {
	SDLRenderer = SDL_CreateRenderer(window.GetSDLWindow(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!SDLRenderer) {
		Log::error(LogCategory::Video, "Failled to create renderer");
		return false;
	}
	return true;
}
void RendererSDL::BeginDraw() {
	SDL_SetRenderDrawColor(SDLRenderer, 120, 120, 255, 255);
	SDL_RenderClear(SDLRenderer);
}
void RendererSDL::EndDraw() {
	SDL_RenderPresent(SDLRenderer);
}
void RendererSDL::DrawRect(Rectangle& rect) {
	SDL_SetRenderDrawColor(SDLRenderer, 255, 255, 255, 255);
	SDL_Rect SDLRect = rect.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &SDLRect);

}
void RendererSDL::Close() {
	SDL_DestroyRenderer(SDLRenderer);
}