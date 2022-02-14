#pragma once
#include"Viewer.h"
class Command {
public: 
	virtual ~Command(){}
	virtual void Execute(Window& window) = 0;
};
