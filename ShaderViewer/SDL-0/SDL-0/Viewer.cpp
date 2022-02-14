#include "Viewer.h"
#include "Assets.h"

int timer; 
bool KEYS[322];  // 322 is the number of SDLK_DOWN events



bool Viewer::Initialize() {
	bool isWindowInit = window.Initialize();
	bool isRendererInit = rendererSDL.Initialize(window);
	return isWindowInit&&isRendererInit;

	for (int i = 0; i < 322; i++) { // init them all to false
		KEYS[i] = false;
	}


}
void Viewer::Load() {
	//Assets::LoadShader("vertexShader.txt", "colorFragShader.txt", "", "", "", "Basic");
	//Log::info("shader loaded");
}
void Viewer::Unload() {

}

void Viewer::Loop() {
	while (isRunning) {
		while (KEYS[SDLK_s]) {
			ProcessInput();
		}
		InputHandler();
		Update();
		Render();
	}
}

void Viewer::Close() {
	rendererOGL.Close();
	rendererSDL.Close();
	window.Close();
	SDL_Quit();
	
}
void Viewer::InputHandler() {
	if (KEYS[SDLK_LEFT]) { // move left
		window.ShiftLeft();
	}
	if (KEYS[SDLK_RIGHT]) { // move right
		window.ShiftRight();
	}
	if (KEYS[SDLK_UP]) { // move up
		window.ShiftUp();
	}
	if (KEYS[SDLK_DOWN]) { // move down
		window.ShiftDown();
	}
	

}
void Viewer::ProcessInput()
{
	

	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);

	//SDl Event
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			KEYS[event.key.keysym.sym] = true;
			break;
		case SDL_KEYUP:
			KEYS[event.key.keysym.sym] = false;
			break;
		default:
			break;
		}

	}
}
void Viewer::Quit() {
	Log::info("j'appuie sur escapeKey");
}

void Viewer::Update() {

	
}
void Viewer::Render() {
	rendererSDL.BeginDraw();
	//rendererOGL.Draw();
	rendererSDL.EndDraw();
}
