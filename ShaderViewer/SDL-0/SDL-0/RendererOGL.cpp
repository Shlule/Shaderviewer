#include "RendererOGL.h"
#include "Rectangle.h"
#include"Assets.h"
#include "Log.h"

#include <glew.h>
#include <SDL.h>

RendererOGL::RendererOGL() :
	window(nullptr),
	context(nullptr),
	vertexArray(nullptr),
	shader(nullptr)
{
}

RendererOGL::~RendererOGL()
{
}

bool RendererOGL::Initialize(Window& windowP)
{
	window = &windowP;

	// Set OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	// Request a color buffer with 8-bits per RGBA channel
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	// Depth buffering
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	// Enable double buffering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	// Force OpenGL to use hardware acceleration
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	// OpenGL Context
	context = SDL_GL_CreateContext(windowP.GetSDLWindow());

	// GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		Log::error(LogCategory::Video, "Failed to initialize GLEW.");
		return false;
	}

	// On some platforms, GLEW will emit a benign error code, so clear it
	glGetError();

	//if (IMG_Init(IMG_INIT_PNG) == 0)
	//{
	//	Log::error(LogCategory::Video, "Unable to initialize SDL_image");
	//	return false;
	//}

	vertexArray = new VertexArray(vertices, 4, indices, 6);
	shader = &Assets::GetShader("basic");
	return true;

}

void RendererOGL::BeginDraw()
{
	glClearColor(0.45f, 0.45f, 1.0f, 1.0f);
	// Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RendererOGL::Draw()
{

}

void RendererOGL::EndDraw()
{
	SDL_GL_SwapWindow(window->GetSDLWindow());
}

void RendererOGL::Close()
{
	
	SDL_GL_DeleteContext(context);
}




