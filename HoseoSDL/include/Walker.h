#pragma once

#include <main.h>

//#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
//#include "SD_ttf"

//#include "usr/include/SDL2/SDL2_gfxPrimitives.h"
//#include "usr/include/SDL2/SDL.h"

#include "InputHandler.h"
#include "Vector2D.h"
#include "Game.h"

#include "Vehicle.h"
#include <vector>

class Walker
{
public:
	Walker();
	void draw(SDL_Renderer* renderer);
	void update();
	void mousemove();

private:
	std::vector<Vehicle*> m_Vehicle;
	Vector2D* m_mousePos;
	Vector2D* target;
};