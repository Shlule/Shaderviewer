#pragma once
#include"Rectangle.h"
#include<SDL.h>
#include"Window.h"

class RendererSDL
{
public:
	RendererSDL();
	RendererSDL(const RendererSDL&) = delete;
	RendererSDL& operator=(const RendererSDL&) = delete;

	bool Initialize(Window& window);
	void BeginDraw();
	void DrawRect(Rectangle& rect);
	void EndDraw();
	void Close();

private:
	SDL_Renderer* SDLRenderer = nullptr;

};

