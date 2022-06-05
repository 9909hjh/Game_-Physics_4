#include "Target.h"
#include <iostream>
#define WIDTH (600)
#define HEIGHT (400)

Target::Target(int _x, int _y) : Vehicle(_x, _y), DistanceFromBoundary(40.0f), DistAway(0)
{
	VehPOS = new Vector2D(0, 0);
	hidespot = new Vector2D(0, 0);
	ToOb = new Vector2D(0, 0);
}

void Target::update()
{
	Vehicle::update();
}

Vector2D Target::Hide(Vector2D* target)
{
	*VehPOS = *target;
	*hidespot = *VehPOS;

	DistAway = (r * 3) + DistanceFromBoundary;

	*ToOb = *m_pos - *target;
	ToOb->normalize();

	*ToOb *= DistAway;
	*ToOb += *m_pos;
	//applyForce(ToOb);
	return *ToOb;
	//return arrive(ToOb);
}

void Target::applyForce(Vector2D* force)
{
	Vehicle::applyForce(force);
}

void Target::draw(SDL_Renderer* renderer)
{
	//Å«¿ø.
	filledCircleRGBA(renderer, m_pos->getX(), m_pos->getY(), (r * 3), 100, 100, 100, 100);
	
	lineRGBA(renderer, m_pos->getX(), m_pos->getY(), 
		VehPOS->getX(), VehPOS->getY(),
		100, 100, 100, 200);

	lineRGBA(renderer, m_pos->getX(), m_pos->getY(),
		ToOb->getX(), ToOb->getY(),
		100, 100, 200, 200);

	circleRGBA(renderer, ToOb->getX(), ToOb->getY(), r / 2, 200, 100, 100, 100);
}