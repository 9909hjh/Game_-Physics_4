#include "Target.h"
#define WIDTH (600)
#define HEIGHT (400)

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
	edges();
	Vehicle::update();
}

void Target::applyForce(Vector2D* force)
{
	Vehicle::applyForce(force);
	//*m_acc += *force;
}

void Target::edges()
{
	if (m_pos->getX() > WIDTH - r)
	{
		m_vel->setX(m_vel->getX() * -1);
		m_pos->setX(WIDTH - r);
	}
	else if (m_pos->getX() < r)
	{
		m_vel->setX(m_vel->getX() * -1);
		m_pos->setX(r);
	}

	if (m_pos->getY() > HEIGHT - r)
	{
		m_vel->setY(m_vel->getY() * -1);
		m_pos->setY(HEIGHT - r);
	}
	else if (m_pos->getY() < r)
	{
		m_vel->setY(m_vel->getY() * -1);
		m_pos->setY(r);
	}
}

void Target::draw(SDL_Renderer* renderer)
{
	//Å«¿ø.
	circleRGBA(renderer, m_pos->getX(), m_pos->getY(), r, 100, 100, 100, 100);
	//lineRGBA(renderer, , , m_pos->getX(), m_pos->getY(), 100, 100, 100, 100);
}