#include "Viewer.h"
#include "Assets.h"

bool Viewer::Initialize() {
	bool isWindowInit = window.Initialize();
	bool isRendererInit = rendererSDL.Initialize(window);
	return isWindowInit&&isRendererInit;
}
void Viewer::Load() {
	Assets::LoadShader("vertexShader.txt", "colorFragShader", "", "", "", "sprite");
}

void Viewer::Loop() {
	while (isRunning) {
		ProcessInput();
		Update();
		Render();
	}
}

void Viewer::Close() {
	rendererSDL.Close();
	window.Close();
	SDL_Quit();
	
}
void Viewer::ProcessInput()
{
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
	rendererOGL.BeginDraw();
	//rendererSDL.Draw();
	rendererOGL.EndDraw();
}
