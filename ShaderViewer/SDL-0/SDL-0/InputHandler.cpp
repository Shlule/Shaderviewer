#include "InputHandler.h"

Command* InputHandler::HandleInput() {
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	if (keyboardState[SDL_SCANCODE_ESCAPE]) {
		return escapeKey;
	}
	if (keyboardState[SDL_SCANCODE_UP]) {
		return upKey;
	}if (keyboardState[SDL_SCANCODE_DOWN]) {
		return downKey;
	}if (keyboardState[SDL_SCANCODE_LEFT]) {
		return leftKey;
	}if (keyboardState[SDL_SCANCODE_RIGHT]) {
		return rightKey;
	}
}
