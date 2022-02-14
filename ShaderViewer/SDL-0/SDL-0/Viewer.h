#pragma once
#include"Window.h"
#include"RendererSDL.h"
#include"RendererOGL.h"
#include"Log.h"
#include"ICommand.h"
#include"InputHandler.h"
class Viewer
{
public:
	static Viewer& Instance() {
		static Viewer inst;
		return inst;
	}
	Viewer(const Viewer&) = delete;
	Viewer& operator= (const Viewer&) = delete;
	Viewer(Viewer&&) = delete;
	Viewer& operator=(Viewer&&) = delete;

private:
	Viewer():isRunning(true){}

public:
	void InputHandler();
	bool Initialize();
	void Load();
	void Loop();
	void Unload();
	void Close();
	void Quit();
	RendererOGL& GetRenderer() { return rendererOGL; }
	

private:
	void ProcessInput();
	void Update();
	void Render();

	Window window;
	bool isRunning;
	RendererSDL rendererSDL;
	RendererOGL rendererOGL;
	
};

