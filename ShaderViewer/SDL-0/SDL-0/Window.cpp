#include "Window.h"
#include "Log.h"
#include<glew.h>

Window::Window() : SDLWindow(nullptr), width(WINDOW_WIDTH), height(WINDOW_HEIGHT)
{
}

bool Window::Initialize()
{
	int sdlInitResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlInitResult != 0) {
		Log::error(LogCategory::Video, "Unable to initialize SDL");
		return false;
	}

	SDLWindow = SDL_CreateWindow("3D Basics", 100, 100, width, height, SDL_WINDOW_OPENGL);
	if (!SDLWindow)
	{
		Log::error(LogCategory::System, "Failed to create window");
		return false;
	}
	return true;
}

void Window::Close()
{
	SDL_DestroyWindow(SDLWindow);
}
