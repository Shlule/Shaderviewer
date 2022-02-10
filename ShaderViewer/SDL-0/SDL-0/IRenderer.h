#pragma once
#include"Window.h"


class IRenderer
{
public:
	enum class Flip {
		None = SDL_FLIP_NONE,
		horizontal = SDL_FLIP_HORIZONTAL,
		vertical = SDL_FLIP_VERTICAL
	};

	enum class Type {SDL, OGL};
	virtual~IRenderer() {};

	virtual bool Initialize(Window& window) = 0;
	virtual void BeginDraw() = 0;
	virtual void Draw() = 0;
	virtual void EndDraw() = 0;
	virtual void Close() = 0;
	virtual IRenderer::Type type() = 0;


};
