#include "Target.h"

Target::Target(int _x, int _y) : Vehicle(_x, _y) 
{
	//*m_vel *= 5;
	m_pos = new Vector2D(_x, 0);
	m_vel = new Vector2D(0, 0);
}

void Target::update()
{
	*m_vel *= 5;
	Vehicle::update();
}

void Target::applyForce(Vector2D* force)
{
	Vehicle::applyForce(force);
	*m_acc += *force;
}

void Target::draw(SDL_Renderer* renderer)
{
	//Å«¿ø.
	circleRGBA(renderer, m_pos->getX(), m_pos->getY(), r * 3, 100, 100, 100, 100);
}