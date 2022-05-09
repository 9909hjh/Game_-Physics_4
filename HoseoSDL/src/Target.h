#pragma once
#include "Vehicle.h"

class Target : public Vehicle
{
public:
	Target(int _x, int _y);
	virtual void draw(SDL_Renderer* renderer);
};