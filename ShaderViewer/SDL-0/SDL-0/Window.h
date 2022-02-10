#pragma once
#include <SDL.h>

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

class Window
{
public:
	Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	bool Initialize();
	void Close();

	SDL_Window* GetSDLWindow() const { return SDLWindow; }
	int GetWidth() const { return width; }
	int GetHeight() const { return height; }

private:
	SDL_Window* SDLWindow;
	int width;
	int height;
};

