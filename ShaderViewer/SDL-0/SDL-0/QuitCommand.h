#pragma once
#include"ICommand.h"
class QuitCommand : public Command {
public: 
	virtual void Execute(Window& window) { return window.Quit(); }
};
