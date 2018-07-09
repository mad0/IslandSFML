#pragma once

#include "engine.h"

class GameState {

public:
	Engine * gameStatePTR;
	virtual void inputs() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual  ~GameState() = 0;
protected:
	//GameState();


};