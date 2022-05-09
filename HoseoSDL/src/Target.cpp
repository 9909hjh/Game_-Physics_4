#include "Target.h"

Target::Target(int _x, int _y) : Vehicle(_x, _y) 
{
	*m_vel *= 5;
}

void Target::draw(SDL_Renderer* renderer)
{
	circleRGBA(renderer, m_pos->getX(), m_pos->getY(), r * 2, 100, 100, 100, 100);
}