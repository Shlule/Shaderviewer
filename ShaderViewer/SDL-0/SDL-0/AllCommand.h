#pragma once
#include"ICommand.h"
class ShiftUpCommand : public Command {
	virtual ~ShiftUpCommand() {};
	virtual void Execute(Window& window) {
		window.ShiftUp();
	}
};

class ShiftDownCommand : public Command {
	virtual ~ShiftDownCommand() {};

	virtual void Execute(Window& window) {
		window.ShiftDown();
	}
};

class ShiftLeftCommand : public Command {
	virtual ~ShiftLeftCommand() {};

	virtual void Execute(Window& window) {
		window.ShiftLeft();
	}
};

class ShiftRightCommand : public Command {
	virtual ~ShiftRightCommand() {};

	virtual void Execute(Window& window) {
		window.ShiftRight();
	}
};
