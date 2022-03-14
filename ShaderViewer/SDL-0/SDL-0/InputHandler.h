#pragma once
#include"ICommand.h"
class InputHandler
{
public:
	Command* HandleInput();

private:
	Command* escapeKey;
	Command* upKey;
	Command* downKey;
	Command* leftKey;
	Command* rightKey;
};
