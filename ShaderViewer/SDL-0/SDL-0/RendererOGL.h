#pragma once
#include"IRenderer.h"
#include"VertexArray.h"
#include"Shader.h"


class RendererOGL : public IRenderer
{
public:

	RendererOGL();
	virtual~RendererOGL();
	RendererOGL(const RendererOGL&) = delete;
	RendererOGL& operator=(const RendererOGL&) = delete;

	bool Initialize(Window& window);
	void BeginDraw();
	void Draw();
	void EndDraw();

	void Close();
	IRenderer::Type type() { return Type::OGL; }

private:
	Shader* shader;
	Window* window;
	VertexArray* vertexArray;
	SDL_GLContext context;

};

