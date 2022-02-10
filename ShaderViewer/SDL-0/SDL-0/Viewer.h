#pragma once
#include"Window.h"
#include"RendererSDL.h"
#include"RendererOGL.h"
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
	bool Initialize();
	void Load();
	void Loop();
	void Unload();
	void Close();
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

