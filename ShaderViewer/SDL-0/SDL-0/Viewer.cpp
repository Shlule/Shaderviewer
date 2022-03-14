#include "Viewer.h"
#include "Assets.h"

int timer; 
bool KEYS[322];  // 322 is the number of SDLK_DOWN events
InputHandler inputHandler;



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
		ProcessInput();
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

void Viewer::ProcessInput()
{
	Command* command = inputHandler.HandleInput();
	if (command) {
		command->Execute(window);
		Log::info("command invoke");
	}
	
	

	//SDl Event
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		}
	}
	
}

void Viewer::Update() {

	
}
void Viewer::Render() {
	rendererSDL.BeginDraw();
	//rendererOGL.Draw();
	rendererSDL.EndDraw();
}
