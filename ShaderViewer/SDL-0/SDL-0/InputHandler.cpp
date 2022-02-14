#include "InputHandler.h"

Command* InputHandler::HandleInput() {
	const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
	if (keyboardState[SDL_SCANCODE_ESCAPE]) {
		return escapeKey;
	}
}
