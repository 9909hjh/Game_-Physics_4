#include "Target.h"

Target::Target(int _x, int _y) : Vehicle(_x, _y) 
{
	//*m_vel *= 5;
	//m_pos = new Vector2D(_x, _y);
	//m_vel = new Vector2D(0, 0);
	//m_vehicle = new Vehicle(0, 0);
	//v_vehcle = new Vector2D(0, 0);
}

void Target::update()
{
	*m_vel *= 5;
	
	//*v_vehcle = *m_pos;
	
	Vehicle::update();
}

void Target::applyForce(Vector2D* force)
{
	Vehicle::applyForce(force);
	//*m_acc += *force;
}

//void pursue(Target* Target)
//{
//	
//}

void Target::draw(SDL_Renderer* renderer)
{
	//Å«¿ø.
	circleRGBA(renderer, m_pos->getX(), m_pos->getY(), r, 100, 100, 100, 100);
	//lineRGBA(renderer, , , m_pos->getX(), m_pos->getY(), 100, 100, 100, 100);
}