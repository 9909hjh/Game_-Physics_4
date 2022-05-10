#pragma once
#include "Vehicle.h"

class Target : public Vehicle
{
public:
	Target(int _x, int _y);
	virtual void update();
	virtual void draw(SDL_Renderer* renderer);
	virtual void applyForce(Vector2D* force);
	//virtual void pursue(Target* Target);
	//
private:
	//Vehicle m_vehicle;
	Vector2D* v_vehcle;
};