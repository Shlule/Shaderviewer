#pragma once
#include"ICommand.h"
class InputHandler
{
public:
	Command* HandleInput();

private:
	Command* escapeKey;
};
